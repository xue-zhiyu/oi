#include <iostream>
#define int long long

using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;
int n, fac[N], ans;

int quick_power(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	for (int i = 1; i <= n; i++)
		ans = ((ans + (i & 1 ? 1 : -1) * (fac[n] * quick_power(fac[i], mod - 2) % mod)) % mod + mod) % mod;
	cout << ((fac[n] - ans) % mod + mod) % mod << endl;
	return 0;
}

