#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

constexpr int N = 1e6 + 10, K = 62;

using pii = pair<int, int>;
using ppi = pair<pii, int>;

template<typename T>
struct lists {
	T e[N];
	int h[N], ne[N], idx;

	void clear(int n) {
		idx = 0;
		for (int i = 1; i <= n; i++) h[i] = 0;
	}

	void push(int u, T dat) {
		++idx;
		e[idx] = dat;
		ne[idx] = h[u];
		h[u] = idx;
	}
};

char s[N];
int n, rk[N], tmp[K], lst, ans[N];
lists<pii> l1, l2;

int get(char ch) {
	if ('0' <= ch && ch <= '9') return ch - '0';
	if ('A' <= ch && ch <= 'Z') return ch - 'A' + 10;
	return ch - 'a' + 36;
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) tmp[get(s[i])] = 1;
	for (int i = 1; i < K; i++) tmp[i] += tmp[i - 1];
	for (int i = 1; i <= n; i++) rk[i] = tmp[get(s[i])];
	lst = tmp[K - 1];
	for (int k = 1; lst < n; k <<= 1) {
		l1.clear(n), l2.clear(n);
		for (int i = 1; i <= n - k; i++) l1.push(rk[i + k], make_pair(rk[i], i));
		for (int i = lst; i >= 1; i--)
			for (int j = l1.h[i]; j; j = l1.ne[j])
				l2.push(l1.e[j].first, make_pair(i, l1.e[j].second));
		for (int i = n; i > n - k; i--) l2.push(rk[i], make_pair(0, i));
		lst = 0;
		pii lpi(0, 0);
		for (int i = 1; l2.h[i]; i++) {
			for (int j = l2.h[i]; j; j = l2.ne[j]) {
				if (lpi.first != i || lpi.second != l2.e[j].first) ++lst;
				rk[l2.e[j].second] = lst;
				lpi = make_pair(i, l2.e[j].first);
			}
		}
	}
	for (int i = 1; i <= n; i++) ans[rk[i]] = i;
	for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? '\n' : ' ');
	return 0;
}

