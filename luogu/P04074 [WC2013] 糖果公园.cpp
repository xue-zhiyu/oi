#include <iostream>

using namespace std;

constexpr int N = 1e5 + 10, M = 2e5 + 10, K = 21;
int n, m, q, v[N], w[N], c[N];
int h[N], e[M], ne[M], idx;
int dfn[M], tot, dep[N], fa[N][K];

void addedge(int u, int v) {
	++idx;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

void dfs(int u, int fat) {
	dfn[++tot] = u;
	fa[u][0] = fat;
	dep[u] = dep[fat] + 1;
	for (int i = 1; i < K; i++)
		fa[u][i] = fa[u][fa[u][i - 1]];
	for (int i = h[u]; i; i = ne[i])
		if (e[i] != fat)
			dfs(e[i], u);
	dfn[++tot] = u;
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = dep[y] - dep[x], j = 0; i; i >>= 1, j++)
		if (i & 1)
			y = fa[y][j];
	if (x == y) return x;
	for (int i = 30; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	return 0;
}

