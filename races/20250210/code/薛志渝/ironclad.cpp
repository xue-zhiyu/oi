#include <algorithm>
#include <iostream>

using namespace std;

using pii = pair<int, int>;

constexpr int N = 5010;
pii a[N];
bool book[N];
int n, id[N], ans[N];

void dfs(int dep, int res) {
	ans[dep] = min(ans[dep], res);
	for (int i = 1; i <= n; i++) {
		if (!book[i]) {
			book[i] = true;
			dfs(dep + 1, res + a[i].first + dep * a[i].second);
			book[i] = false;
		}
	}
}

int main() {
	freopen("ironclad.in", "r", stdin);
	freopen("ironclad.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; i++) ans[i] = 0x7fffffff;
	dfs(0, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}

