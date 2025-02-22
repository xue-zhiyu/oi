#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	double ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int sum = 0, mxn = 0, mnn = 11;
		for (int j = 1; j <= m; j++) {
			int t;
			cin >> t;
			sum += t;
			mxn = max(mxn, t);
			mnn = min(mnn, t);
		}
		ans = max(ans, ((sum - mxn - mnn) * 1.) / (m - 2));
	}
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}

