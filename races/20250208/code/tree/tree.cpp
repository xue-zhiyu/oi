#include <cstring>
#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

constexpr int N = 1e5 + 10, M = 2e5 + 10, K = 15, mod = 1e9 + 7;

int n, q, h[N], e[M], ne[M], idx;

int ind[N], ys[N], fys[N], c[N];

bool broken[N];
int m, f[N][K];

void addedge(int u, int v) {
	++idx;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	ind[v]++;
}

bool isLian() {
	if (n == 1) return true;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 1) cnt1++;
		else if (ind[i] == 2) cnt2++;
		else return false;
	}
	return cnt1 == 2;
}

void ysLian() {
	int zl = 1, lst = 0;
	while (ne[h[zl]]) {
		if (e[h[zl]] == lst) {
			lst = zl;
			zl = e[ne[h[zl]]];
		} else {
			lst = zl;
			zl = e[h[zl]];
		}
	}
	int zr = zl, tot = 0;
	lst = 0;
	while (ne[h[zr]] || zr == zl) {
		ys[++tot] = zr;
		if (e[h[zr]] == lst) {
			lst = zr;
			zr = e[ne[h[zr]]];
		} else {
			lst = zr;
			zr = e[h[zr]];
		}
	}
	ys[++tot] = zr;
	for (int i = 1; i <= n; i++) fys[ys[i]] = i;
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

int findLenRight(int x) {
	int color = getsum(x), res = 0, cur = 0;
	for (int i = 20; ~i; i--) {
		res += 1 << i;
		if (res > n) {
			res -= 1 << i;
			continue;
		}
		cur += c[res];
		if (cur > color) {
			cur -= c[res];
			res -= 1 << i;
		}
	}
	return res;
}

int findLenLeft(int x) {
	int l = 1, r = x, color = getsum(x);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (getsum(mid) != color) l = mid + 1;
		else r = mid;
	}
	return l;
}

int findLen(int x) {
	return findLenRight(x) - findLenLeft(x) + 1;
}

void dp(int u, int fat) {
	f[u][1] = 1;
	for (int i = h[u]; i; i = ne[i]) {
		if (e[i] != fat && !broken[i]) {
			dp(e[i], u);
			for (int j = m; j >= 1; j--)
				for (int k = j - 1; k >= 1; k--)
					f[u][j] = (f[u][j] + f[u][j - k] * f[e[i]][k] % mod) % mod;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	if (isLian()) {
		ysLian();
		while (q --> 0) {
			int opt, a, b;
			cin >> opt >> a >> b;
			if (opt) {
				cout << max(findLen(fys[a]) - b + 1, 0ll) << endl;
			} else {
				int ta = fys[a], tb = fys[b];
				if (ta > tb) swap(ta, tb);
				if (getsum(ta) != getsum(tb)) {
					update(tb, -1);
				} else {
					update(tb, 1);
				}
			}
		}
	} else {
		while (q --> 0) {
			int opt, a, b;
			cin >> opt >> a >> b;
			if (opt) {
				for (int i = 1; i <= n; i++)
					for (int j = 0; j < K; j++)
						f[i][j] = 0;
				m = b;
				dp(a, 0);
				cout << f[a][b] << endl;
			} else {
				for (int u = 1; u <= n; u++)
					for (int i = h[u]; i; i = ne[i])
						if ((u == a && e[i] == b) || (u == b && e[i] == a))
							broken[i] = !broken[i];
			}
		}
	}
	return 0;
}

