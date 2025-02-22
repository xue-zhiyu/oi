#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long

using namespace std;

using pii = pair<int, int>;

constexpr int N = 1e5 + 10, M = 6e5 + 10;
int n, m;

int h[N], eu[M], ev[M], ew[M], ne[M], idx = 1, scs, ans = 0x7fffffffffffffffll;

void init() {
	memset(h, 0, sizeof(h));
	idx = 0;
}

void addedge(int u, int v, int w) {
	++idx;
	eu[idx] = u, ev[idx] = v, ew[idx] = w;
	ne[idx] = h[u];
	h[u] = idx;
}

bool isonscs[M];
int kid[M / 2], f[N];

int findBoss(int x) {
	return f[x] == x ? x : f[x] = findBoss(f[x]);
}

void kruscal() {
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) kid[i] = i;
	sort(kid + 1, kid + m + 1, [&](int i, int j) { return ew[i << 1] < ew[j << 1]; });
	int tot = 0;
	for (int i = 1; tot < n - 1; i++) {
		if (findBoss(eu[kid[i] << 1]) != findBoss(ev[kid[i] << 1]))  {
			++tot;
			isonscs[kid[i] << 1] = isonscs[(kid[i] << 1) ^ 1] = true;
			f[findBoss(eu[kid[i] << 1])] = findBoss(ev[kid[i] << 1]);
			scs += ew[kid[i] << 1];
		}
	}
}

pii dat[N][31];
int fa[N][31], dep[N];

pii merge_dat(pii a, pii b) {
	if (b.first > a.first) a.second = a.first, a.first = b.first;
	else if (b.first > a.second && b.first != a.first) a.second = b.first;
	if (b.second > a.first) a.second = a.first, a.first = b.second;
	else if (b.second > a.second && b.second != a.second) a.second = b.second;
	return a;
}

void lca_dfs(int u, int fat) {
	fa[u][0] = fat;
	dep[u] = dep[fat] + 1;
	for (int i = h[u]; i; i = ne[i])
		if (ev[i] == fat && isonscs[i])
			dat[u][0] = {ew[i], -1};
	for (int i = 1; i < 31; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1],
		dat[u][i] = merge_dat(dat[u][i - 1], dat[fa[u][i - 1]][i - 1]);
	for (int i = h[u]; i; i = ne[i])
		if (ev[i] != fat && isonscs[i])
			lca_dfs(ev[i], u);
}

pii query(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	pii res = {-1, -1};
	for (int i = dep[u] - dep[v], j = 0; i; i >>= 1, j++)
		if (i & 1)
			res = merge_dat(res, dat[u][j]), u = fa[u][j];
	if (u == v) return res;
	for (int i = 30; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			res = merge_dat(res, merge_dat(dat[u][i], dat[v][i])),
			u = fa[u][i], v = fa[v][i];
	return merge_dat(res, merge_dat(dat[u][0], dat[v][0]));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u == v) {
			idx += 2;
			continue;
		}
		addedge(u, v, w);
		addedge(v, u, w);
	}
	kruscal();
	lca_dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		if (!eu[i << 1]) continue;
		if (isonscs[i << 1]) continue;
		pii t = query(eu[i << 1], ev[i << 1]);
		if (t.first == ew[i << 1]) t.first = t.second;
		if (t.first == -1) continue;
		ans = min(ans, scs - t.first + ew[i << 1]);
	}
	cout << ans << endl;
	return 0;
}

