#include <algorithm>
#include <iostream>
#define int long long

using namespace std;

constexpr int N = 2e5 + 10;
int n, a[N], d[N], id[N], ans, cur;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> d[i], id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) { return a[i] < a[j]; });
	for (int i = 1; i <= n; i++) {
		cur += a[id[i]];
		ans += d[id[i]] - cur;
	}
	cout << ans << endl;
	return 0;
}

