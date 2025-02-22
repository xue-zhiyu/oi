#include <iostream>
#define int long long

using namespace std;

int n, mx, sum;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		mx = max(mx, t), sum += t;
	}
	cout << max(2 * mx, sum) << endl;
	return 0;
}

