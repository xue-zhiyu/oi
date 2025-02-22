#include <iostream>

using namespace std;

constexpr int N = 2e5 + 10, M = 4e5 + 10;
int n, m, h[N], e[M], ne[M], idx, f[N], gs[N], curColor, cnt[N], siz[N];

void addedge(int u, int v) {
	++idx;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

int findBoss(int x) {
	return f[x] == x ? x : f[x] = findBoss(f[x]);
}

void merge(int x, int y) {
	f[findBoss(x)] = findBoss(y);
}

void dfs(int u) {
	gs[u] = curColor;
	for (int i = h[u]; i; i = ne[i])
		if (!gs[e[i]])
			dfs(e[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
		merge(u, v);
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		if (!gs[i]) {
			++curColor;
			dfs(i);
		}
	}
	for (int u = 1; u <= n; u++)
		for (int i = h[u]; i; i = ne[i])
			cnt[gs[e[i]]]++;
	for (int i = 1; i <= n; i++) siz[gs[i]]++;
	for (int i = 1; i <= curColor; i++) cnt[i] = (cnt[i] >> 1) - siz[i] + 1;
	for (int i = 1; i <= curColor; i++) {
		for (int j = 0; j < cnt[i]) {
			
		}
	}
	return 0;
}

