#include <iostream>
#define int long long

using namespace std;

int n, k, m;

bool check(int mid) {
	int cur = 0;
	for (int i = 1; i <= k; i++) {
		int y = max(m, (n - cur) / mid);
		cur += y;
		if (cur >= n) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> m;
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}

