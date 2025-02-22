#include <iomanip>
#include <iostream>

using namespace std;

constexpr int N = 3010, M = 10010;
int n, m, u[M], v[M];
double w[M], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i];
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = i ? 1e12 : 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			f[i + 1][v[j]] = min(f[i + 1][v[j]], f[i][u[j]] + w[j]);
	double ans = 1e7;
	for (int i = 1; i <= n; i++) {
		if (f[n][i] < 1e11) {
			double tmp = -1e12;
			for (int j = 0; j < n; j++) tmp = max(tmp, (f[n][i] - f[j][i]) / (n - j));
			ans = min(ans, tmp);
		}
	}
	cout << fixed << setprecision(8) << ans << endl;
	return 0;
}

