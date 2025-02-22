#include <algorithm>
#include <cmath>
#include <iostream>
#define endl '\n'

using namespace std;

using ll = long long;

constexpr int N = 20, M = 2e5 + 10, mod = 1919810;
int n, m, tot;
ll a[N], ys[M], ans[M], cnt;

bool is_zero(ll x) {
	x %= mod;
	ll res = 0, tmp = 1;
	for (int i = 0; i <= n; i++, tmp = tmp * x % mod) res = ((res + (a[i] % mod) * tmp % mod) % mod + mod) % mod;
	return !res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) cin >> a[i];
	int abs0 = abs(a[0]);
	for (ll i = 1; i * i <= abs0; i++) {
		if (abs0 % i == 0) {
			ys[++tot] = i;
			if (i * i != abs0) ys[++tot] = abs0 / i;
		}
	}
	sort(ys + 1, ys + tot + 1);
	while (m --> 0) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int i;
			ll val;
			cin >> i >> val;
			a[i] = val;
		} else {
			cnt = 0;
			for (int i = 1; i <= tot; i++) {
				if (is_zero(ys[i])) ans[++cnt] = ys[i];
				if (is_zero(-ys[i])) ans[++cnt] = -ys[i];
			}
			cout << cnt << endl;
			for (int i = 1; i <= cnt; i++) cout << ans[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}

