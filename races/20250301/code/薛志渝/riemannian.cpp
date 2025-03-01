#include <iostream>
#include <vector>
#define int long long
#define _mul(__a__, __b__, __c__, i, j) __c__[i][j] = (__a__[i][0] * __b__[0][j] % mod + __a__[i][1] * __b__[1][j] % mod + __a__[i][2] * __b__[2][j] % mod) % mod;
#define mul(__a__, __b__, __c__) {_mul(__a__, __b__, __c__, 0, 0) _mul(__a__, __b__, __c__, 0, 1) _mul(__a__, __b__, __c__, 0, 2) \
								  _mul(__a__, __b__, __c__, 1, 0) _mul(__a__, __b__, __c__, 1, 1) _mul(__a__, __b__, __c__, 1, 2) \
								  _mul(__a__, __b__, __c__, 2, 0) _mul(__a__, __b__, __c__, 2, 1) _mul(__a__, __b__, __c__, 2, 2)}
#define copy(__source__, __data__)  __data__[0][0] = __source__[0][0], __data__[0][1] = __source__[0][1], __data__[0][2] = __source__[0][2], \
									__data__[1][0] = __source__[1][0], __data__[1][1] = __source__[1][1], __data__[1][2] = __source__[1][2], \
									__data__[2][0] = __source__[2][0], __data__[2][1] = __source__[2][1], __data__[2][2] = __source__[2][2];

using namespace std;

constexpr int mt[3][3] = {
	{0, 2, 1},
	{1, 2, 2},
	{0, 0, 1}
}, one[3][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
};
constexpr int mod = 998244353;
int n, b[3][3], r[3][3], t[3][3], ans1, ans2;

int read() {
	int res = 0; char ch = fgetc(stdin);
	while (ch < '0' || ch > '9') ch = fgetc(stdin);
	while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = fgetc(stdin);
	return res;
}

void quick_power(int power) {
	copy(mt, b)
	copy(one, r);
	while (power) {
		if (power & 1) {
			mul(b, r, t);
			copy(t, r)
		}
		mul(b, b, t);
		copy(t, b)
		power >>= 1;
	}
}

void solve() {
	n = read();
	quick_power(n - 1);
	ans1 ^= ((r[0][0] + 2 * r[0][1] + r[0][2]) % mod), ans2 ^= ((r[1][0] + 2 * r[1][1] + r[1][2]) % mod);
}

signed main() {
	freopen("riemannian.in", "r", stdin);
	freopen("riemannian.out", "w", stdout);
	int T = read();
	while (T --> 0) solve();
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}

