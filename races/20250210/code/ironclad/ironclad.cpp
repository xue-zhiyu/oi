#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#define int long long

using namespace std;

constexpr int N = 5010;
int n, a[N], b[N], id[N], f[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) { return b[i] > b[j]; });
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i <= n; i++) f[i][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] + a[id[i]] + (j - 1) * b[id[i]]);
	for (int i = 1; i <= n; i++) cout << f[n][i] << endl;
	return 0;
}

