#include <iostream>
#define endl '\n'

using namespace std;

constexpr int N = 110, K = 5;
int n, k, a[N], cnt[K][N], f[N][N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]][i]++;
	for (int j = 1; j <= k; j++)
		for(int i = 2; i <= n; i++)
			cnt[j][i] += cnt[j][i - 1];
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (bool(cnt[1][r] - cnt[1][l - 1]) + bool(cnt[2][r] - cnt[2][l - 1]) + bool(cnt[3][r] - cnt[3][l - 1]) == 1) {
				f[l][r] = 1;
				continue;
			}
			f[l][r] = r - l + 1;
			for (int i = l; i < r; i++) f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r]);
			for (int i = 1; i < len; i++) {
				if (len % i) continue;
				if (f[l][l + i - 1] >= f[l][r]) continue;
				bool flag = true;
				for (int j = 1; j < len / i && flag; j++)
					for (int k = 1; k <= i && flag; k++)
						if (a[l + i * j + k - 1] != a[l + i * (j - 1) + k - 1])
							flag = false;
				if (!flag) continue;
				f[l][r] = f[l][l + i - 1];
			}
		}
	}
	if (f[1][n] <= k) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T --> 0) solve();
	return 0;
}

