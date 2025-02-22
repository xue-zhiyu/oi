#include <iostream>
#define int long long

using namespace std;

constexpr int N = 2e5 + 10;
int n, m, a[N], ans;

bool check(int mid) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += mid / a[i];
		if (res >= m) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 0, r = 1e18;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}

