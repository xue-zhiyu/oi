#include <algorithm>
#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

constexpr int N = 1e5 + 10;
int n, k, a1[N], a2[N], tot1, tot2, ans;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (t & 1) a1[++tot1] = t;
		else a2[++tot2] = t;
	}
	if (tot1 >= k) {
		sort(a1 + 1, a1 + n + 1, [](int i, int j) { return i > j; });
		int tmp = 0;
		for (int i = 1; i <= k; i++) tmp += a1[i];
		ans = max(ans, tmp);
	}
	if (tot2 >= k) {
		sort(a2 + 1, a2 + n + 1, [](int i, int j) { return i > j; });
		int tmp = 0;
		for (int i = 1; i <= k; i++) tmp += a2[i];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}

