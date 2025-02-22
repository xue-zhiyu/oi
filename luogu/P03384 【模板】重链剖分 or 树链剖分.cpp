#include <iostream>
#define int long long

using namespace std;

constexpr int N = 1e5 + 10, M = 2e5 + 10;
int n, m, root, mod, a[N], h[N], e[M], ne[M], idx;
int fa[N], siz[N], hson[N], curdfn, dfn[N], l[N], r[N];

void addedge(int u, int v) {
	++idx;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

void dfs1(int u, int fat) {
	siz[u] = 1;
	fa[u] = fat;
	for (int i = h[u]; i; i = ne[i]) {
		if (e[i] != fat) {
			dfs1(e[i], u);
			siz[u] += siz[e[i]];
			if (siz[e[i]] > siz[hson[u]]) hson[u] = e[i];
		}
	}
}

void dfs2(int u, int cur) {
	dfn[u] = ++curdfn;
	if (u == cur) l[u] = r[u] = dfn[u];
	else r[cur] = dfn[u];
	if (hson[u]) dfs2(hson[u], cur);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> root >> mod;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	dfs1(root, 0);
	for (int i = 1; i <= n; i++) cout << siz[i] << (i == n ? '\n' : ' ');
	for (int i = 1; i <= n; i++) cout << hson[i] << (i == n ? '\n' : ' ');
	return 0;
}

