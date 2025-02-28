#include <ctime>
#include <iostream>
#include <random>
#define space fputc(' ', stdout)
#define endl fputc('\n', stdout)

using namespace std;

using ll = long long;
mt19937_64 rd(time(nullptr));

int stk[50], top;

void write(ll x) {
	if (!x) {
		fputc('0', stdout);
		return;
	}
	while (x) {
		stk[++top] = x % 10;
		x /= 10;
	}
	while (top) fputc(stk[top--] + '0', stdout);
}

int main() {
	int T = 1;
	for (int cur = 1; cur <= T; cur++) {
		freopen("dat.in", "w", stdout);
		ll n = 1e7, m = 1e7;
		write(n); space; write(m); endl;
		for (int i = 1; i <= n; i++) write(rd() % 20 + 1), fputc(" \n"[i == n], stdout);
		cerr << "ok" << '\n';
		while (m --> 0) {
			int l, r;
			l = rd() % n + 1, r = rd() % min(n - l - 1, 10ll) + 1; int l1 = l, r1 = l + r - 1;
			l = rd() % n + 1, r = rd() % min(n - l - 1, 10ll) + 1; int l2 = l, r2 = l + r - 1;
			write(l1), space, write(r1), space;
			write(l2), space, write(r2), endl;
		}
	}
	return 0;
}

