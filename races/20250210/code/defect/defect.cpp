#include <iostream>
#define int long long
#define getbitat(_x_, _i_) (((_x_) >> (_i_)) & 1)
#define getbitle(_x_, _i_) ((_x_) & ((1ll << (_i_ + 1)) - 1))

using namespace std;

constexpr int N = 1e6 + 10;
int n, a[N], ans;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ans = 0;
	for (int i = 61; ~i; i--) {
		int val = 0, cnt = 0;
		for (int j = 1; j <= n; j++) val ^= getbitat(a[j], i), cnt += !getbitat(a[j], i);
		if (val) {
			if (cnt) {
				int id = 0;
				for (int j = 1; j <= n; j++)
					if (!getbitat(a[j], i) && (!id || getbitle(a[id], i - 1) < getbitle(a[j], i - 1)))
						id = j;
				ans += (1 << i) - getbitle(a[id], i - 1);
				a[id] = a[id] - getbitle(a[id], i - 1) + (1 << i);
			} else {
				int kid = 0, kres = 0, kp1 = 0, kp2 = 0;
				for (int k = 61; k > i; k--) {
					int p1 = 0, p2 = 0;
					for (int j = 1; j <= n; j++) {
						if (!getbitat(a[j], k)) {
							if (getbitle(a[p1], k - 1) < getbitle(a[j], k - 1)) p2 = p1, p1 = j;
							else if (getbitle(a[p2], k - 1) < getbitle(a[j], k - 1)) p2 = j;
						}
					}
					if (!p2) continue;
					int res = (1 << k) - getbitle(a[p1], k - 1) + (1 << k) - getbitle(a[p2], k - 1);
					int t1 = a[p1], t2 = a[p2];
					a[p1] = a[p1] - getbitle(a[p1], k - 1) + (1 << k);
					a[p2] = a[p2] - getbitle(a[p2], k - 1) + (1 << k);
					int id = 0;
					for (int j = 1; j <= n; j++)
						if (!getbitat(a[j], i) && (!id || getbitle(a[id], i - 1) < getbitle(a[j], id - 1)))
							id = j;
					res += (1 << i) - getbitle(a[id], i - 1);
					a[p1] = t1, a[p2] = t2;
					if (!kid || res < kres) {
						kid = k, kres = res;
						kp1 = p1, kp2 = p1;
					}
				}
				int res = (1 << kid) - getbitle(a[kp1], kid - 1) + (1 << kid) - getbitle(a[kp2], kid - 1), id = 0;
				a[kp1] = a[kp1] - getbitle(a[kp1], kid - 1) + (1 << kid);
				a[kp2] = a[kp2] - getbitle(a[kp2], kid - 1) + (1 << kid);
				for (int j = 1; j <= n; j++)
					if (!getbitat(a[j], i) && (!id || getbitle(a[id], i - 1) < getbitle(a[j], id - 1)))
						id = j;
				res += (1 << i) - getbitle(a[id], i - 1);
				ans += res;
				a[id] = a[id] - getbitle(a[id], i - 1) + (1 << i);
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T --> 0) solve();
	return 0;
}

