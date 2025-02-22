#include <iostream>
#define int long long

using namespace std;

constexpr int mod = 998244353;

signed main() {
	int T;
	cin >> T;
	while (T --> 0) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i * i <= n; i++) ans = ((ans + ((3 * i % mod - 2) % mod * (2 * (n / i) % mod - 2 * i % mod + 1) % mod + (n / i) % mod - i) % mod) + mod) % mod;
		cout << ans << endl;
	}
	return 0;
}

