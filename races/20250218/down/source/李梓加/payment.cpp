#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	cin.tie(0)->sync_with_stdio(false);
	ll n, m, k, g;
	cin >> n >> m >> k; g = n + 1;
	ll x = 0;
	while (g >= n) {
		x++;
		g = 0;
		for (ll i = 1; i <= k; ++i) {
			ll y = (n - g) / x;
			if (y < m) y = m;
			g += y;
		}
	}
	cout << x - 1 << endl;
	return 0;
}
