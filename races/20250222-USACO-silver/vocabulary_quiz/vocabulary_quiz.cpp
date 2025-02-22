#include <iostream>

using namespace std;

constexpr int N = 1e6 + 10;
int n, m, fa[N][31], h[N], e[N], ne[N], idx, oud[N], dfn[N], nex[N], curdfn, c[N], dep[N];

void addedge(int u, int v) {
	++idx;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

void dfs(int u) {
	dep[u] = dep[fa[u][0]] + 1;
	cout << u << ": " << fa[u][0] << ' ' << dep[fa[u][0]] << endl;
	dfn[u] = ++curdfn;
	for (int i = 0; i < 31; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; i; i = ne[i]) dfs(e[i]);
	nex[u] = curdfn;
}

int lowbit(int x) {
	return x & -x;
}

void update(int k, int x) {
	while (k <= n) {
		c[k] += x;
		k += lowbit(k);
	}
}

int getsum(int k) {
	int res = 0;
	while (k) {
		res += c[k];
		k -= lowbit(k);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> fa[i][0];
		fa[i][0]++;
		addedge(fa[i][0], i + 1);
		oud[fa[i][0]]++;
	}
	n++;
	dfs(1);
	for (int i = 1; i <= n; i++) cout << dep[i] << ' ';
	for (int i = 1; i <= n; i++)
		if (!oud[i])
			m++;
	return 0;
}

