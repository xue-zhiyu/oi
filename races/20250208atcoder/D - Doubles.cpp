#include <iomanip>
#include <iostream>
#define int long long

using namespace std;

constexpr int N = 110, M = 1e5 + 10;
long double ans;
int n, k[N], book[N][M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int t;
			cin >> t;
			book[i][t]++;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int sum = 0;
			for (int l = 1; l < M; l++) sum += book[i][l] * book[j][l];
			ans = max(ans, ((long double) sum) / (k[i] * k[j]));
		}
	}
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}

