#include <algorithm>
#include <iomanip>
#include <iostream>
#define int long long

using namespace std;

constexpr int N = 10010;
int n, m, w[N], v[N], id[N], f[N][3], ans;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i], id[i] = 1;
	sort(id + 1, id + n + 1, [&](int i, int j) { return w[i] < w[j]; });
	f[0][1] = f[0][2] = -0x3f3f3f3f3f3f3f3fll;
	for (int j = 1; j <= n; j++) {
		for (int i = m; i >= 1; i--) {
			if (j == 1) {
				if (i >= w[id[j]]) f[i][1] = max(f[i][1], f[i - w[id[j]]][0] + v[id[j]]);
			} else {
				if (i >= w[id[j]]) f[i][0] = max(f[i][0], f[i - w[id[j]]][0] + v[id[j]]),
								   f[i][1] = max(f[i][1], f[i - w[id[j]]][1] + v[id[j]]),
								   f[i][2] = max(f[i][2], f[i - w[id[j]]][2] + v[id[j]]);
				if (i >= w[id[1]]) f[i][2] = max(f[i][2], id[1][i - w[1]]id[j]1] + v[j]);
			}
		}
	}
	ans = max(max(ans, f[m][0]), max(f[m][1], f[m][2]));
	cout << ans << endl;
	return 0;
}

