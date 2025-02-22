#include <iostream>
#define int long long

using namespace std;

constexpr int N = 510, N2 = 250010, mod = 1e9 + 7;

int quick_power(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

int n, m, k, fac[N], inv[N], pow2[N2], ans;

signed main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 2) {
		fac[0] = 1;
		for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
		inv[N - 1] = 128976362;
		for (int i = N - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
		pow2[0] = 1;
		for (int i = 1; i < N2; i++) pow2[i] = (pow2[i - 1] << 1) % mod;
		int sy = n * m;
		for (int i = 1; i <= n && i <= m; i++) {
			sy -= (n + m - i * 2 + 1);
			int tmp = fac[n] * fac[m] % mod * inv[n - i] % mod * inv[m - i] % mod * inv[i] % mod * pow2[sy] % mod;
			if (i & 1) ans = (ans + tmp) % mod;
			else ans = ((ans - tmp) % mod + mod) % mod;
		}
		cout << ans << endl;
	} else if (m == 2) {
		for (int i = 1; i < k; i++) ans = (ans + quick_power(i, n)) % mod;
		ans = ans * 2 % mod * n % mod * quick_power(k, n - 1) % mod;
		for (int i = 1; i < k; i++)
			for (int j = 1; j < k; j++)
				ans = ((ans - n * (n - 1) % mod * min(i, j) % mod * min(i, j) % mod * quick_power(i, n - 1) % mod * quick_power(j, n - 1) % mod) % mod + mod) % mod;
		cout << ans << endl;
	}
	return 0;
}

