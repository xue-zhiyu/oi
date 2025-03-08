#include <algorithm>
#include <iostream>
#define int long long

using namespace std;

int read() {
	int x = 0, f = 1; char ch = fgetc(stdin);
	while (ch < '0' || ch > '9') { f = (ch == '-' ? -1 : f); ch = fgetc(stdin); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = fgetc(stdin); }
	return x * f;
}

int _STK_[100], _STK_TOP_;

void write(int x) {
	if (!x) {
		fputc('0', stdout);
		return;
	}
	if (x < 0) {
		fputc('-', stdout);
		x = -x;
	}
	while (x) _STK_[++_STK_TOP_] = x % 10, x /= 10;
	while (_STK_TOP_) fputc(_STK_[_STK_TOP_--] + '0', stdout);
}

constexpr int N = 70, K = 10;

namespace solve1 {
	int n, q, a[N];

	void solve() {
		n = read();
		for (int i = 0; i <= n; i++) a[i] = read();
		q = read();
		while (q --> 0) {
			int l = read(), r = read(), res = -0x7f7f7f7f7f7f7f7f;
			for (int i = l; i <= r; i++) res = max(res, a[i]);
			write(res); fputc('\n', stdout);
		}
	}
}

namespace solve2 {
	int n, q, a[N], b[N], m;

	void solve() {
		n = read(), m = read();
		a[0] = 1;
		for (int i = 1; i <= n; i++) a[i] = 0;
		for (int k = 1; k <= n; k++) {
			int r = read();
			for (int i = 0; i <= k; i++) b[i] = 0;
			for (int i = 0; i <= k; i++) b[i + 1] += a[i], b[i] -= r * a[i];
			for (int i = 0; i <= k; i++) a[i] = b[i];
		}
		q = read();
		reverse(a, a + n + 1);
		for (int i = 0; i <= n; i++) a[i] = m * a[i];
		while (q --> 0) {
			int l = read(), r = read(), res = -0x7f7f7f7f7f7f7f7f;
			for (int i = l; i <= r; i++) res = max(res, a[i]);
			write(res); fputc('\n', stdout);
		}
	}
}

signed main() {
	int fwnum = read();
	if (fwnum != 1) {
		solve2::solve();
	} else {
		solve1::solve();
	}
	return 0;
}

