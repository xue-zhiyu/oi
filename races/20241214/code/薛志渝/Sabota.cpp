#include <iomanip>
#include <iostream>

using namespace std;

constexpr int N = 5e5 + 10;
double f[N], ans = 0.;
int n, k, p[N], siz[N], h[N], e[N], ne[N], idx;

void addedge(int u, int v) {
	++idx;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

void dfs(int u) {
	f[u] = 0.;
	if (!h[u]) f[u] = 1;
	for (int i = h[u]; i; i = ne[i]) {
		dfs(e[i]);
		f[u] = max(f[u], min(f[e[i]], siz[e[i]] * 1. / (siz[u] - 1)));
	}
}

int main() {
	freopen("Sabota.in", "r", stdin);
	freopen("Sabota.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 2; i <= n; i++) cin >> p[i], addedge(p[i], i);
	for (int i = n; i >= 1; i--) siz[p[i]] += (++siz[i]);
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (siz[i] > k)
			ans = max(ans, f[i]);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}

