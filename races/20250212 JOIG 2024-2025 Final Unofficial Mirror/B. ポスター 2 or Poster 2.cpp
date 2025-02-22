#include <iostream>
#include <set>
#define int long long

using namespace std;

constexpr int N = 310, dx[] = {0, 1, 1, 0}, dy[] = {0, 0, 1, 1};
set<int> s, col;
bool b[N][N];
int n, k, a[N][N], res, ans = 0;

bool calc(int i, int j) {
	if (i == n || j == n) return false;
	s.clear();
	for (int k = 0; k < 4; k++) s.insert(a[i + dx[k]][j + dy[k]]);
	return s.size() >= 3;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			res += (b[i][j] = calc(i, j));
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int ta = a[x][y];
			col.clear();
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
					if (!(x + i < 1 || x + i > n || y + j < 1 || y + j > n))
						col.insert(a[x + i][y + j]);
			for (int i : col) {
				a[x][y] = i;
				int tmp = 0;
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						if (!(x + i < 1 || x + i > n || y + j < 1 || y + j > n))
							tmp = tmp - b[x + i][y + j] + calc(x + i, y + j);
				ans = max(ans, tmp);
				a[x][y] = ta;
			}
			if (col.size() < k) {
				a[x][y] = k + 1;
				int tmp = 0;
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						if (!(x + i < 1 || x + i > n || y + j < 1 || y + j > n))
							tmp = tmp - b[x + i][y + j] + calc(x + i, y + j);
				ans = max(ans, tmp);
				a[x][y] = ta;
			}
		}
	}
	cout << res + ans << endl;
	return 0;
}

