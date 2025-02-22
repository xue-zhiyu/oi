#include <algorithm>
#include <cstring>
#include <iostream>
#include <functional>

using namespace std;

constexpr int N = 4e5 + 10;

using pii = pair<int, int>;
using ppi = pair<pii, int>;

ppi a[N];
char s[N];
int n, m, rk[N], tmp[128], id[N], lst;

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) s[n + i] = s[i];
	m = (n << 1);
	for (int i = 1; i <= n; i++) tmp[(int) s[i]] = 1;
	for (int i = 1; i < 128; i++) tmp[i] += tmp[i - 1];
	for (int i = 1; i <= m; i++) rk[i] = tmp[(int) s[i]];
	lst = tmp[127];
	for (int k = 1; lst < m; k <<= 1) {
		for (int i = 1; i <= m; i++) a[i] = make_pair(make_pair(rk[i], rk[i + k]), i);
		sort(a + 1, a + m + 1);
		lst = 0;
		for (int i = 1; i <= m; i++) {
			if (a[i].first != a[i - 1].first) ++lst;
			rk[a[i].second] = lst;
		}
	}
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) { return rk[i] < rk[j]; });
	for (int i = 1; i <= n; i++) cout << s[(id[i] + n - 2) % n + 1];
	return 0;
}

