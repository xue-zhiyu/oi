#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 998244353;
int main() {
	cin.tie(0)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		ll n, ans = 0, t;
		cin >> n;
		t = n / 2; ans += n - t;
		deque<pair<ll, ll>>dq;
		ll tmp = 0;
		for (ll l = 1, r; l <= n; l = r + 1) {
			r = min(n / (n / l), n);
			dq.emplace_back(r - l + 1, n / l);
			tmp += (r - l + 1) * (n / l) % mod;
			tmp %= mod;
		}
		ans += tmp;
		if (2 <= t)
			for (ll L = 2, R; L <= t; L = R + 1) {
				R = min(n / (n / L), t);
				if (dq.size() == 1) {
					tmp -= dq.front().first * dq.front().second % mod;
					dq.front().first--; dq.front().second--;
					tmp += dq.front().first * dq.front().second % mod;
					tmp %= mod;
				}
				else {
					ll s = dq.front().first;
					tmp -= dq.front().first * dq.front().second % mod;
					tmp %= mod;
					dq.pop_front();
					tmp -= dq.back().first * dq.back().second % mod;
					tmp %= mod;
					dq.pop_back();
					tmp += s * dq.front().second % mod;
					dq.front().first += s;
					tmp = (tmp % mod + mod) % mod;
				}
				ans += tmp * (R - L + 1) % mod;
				ans %= mod;
			}
		cout << ans << endl;
	}
	return 0;
}
/*
我是个**
成功在ll上卡了0.5h
*/
