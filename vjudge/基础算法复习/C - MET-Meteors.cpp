#include <iostream>
#define int long long

using namespace std;

struct num {
	int id, p;
};

struct rain {
	int l, r, p;
};

constexpr int N = 3e5 + 10;
bool nie[N];
int n, m, k, o[N], ans[N];
rain b[N];
num a[N], a1[N], a2[N];
int h[N], e[N], ne[N], idx, c[N];

int lowbit(int x) {
	return x & -x;
}

void update(int k, int x) {
	while (k <= m) {
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

void updateInterval(int l, int r, int x) {
	if (l <= r) {
		update(l, x);
		update(r + 1, -x);
	} else {
		updateInterval(1, l, x);
		updateInterval(r, m, x);
	}
}

void push(int u, int dat) {
	++idx;
	e[idx] = dat;
	ne[idx] = h[u];
	h[u] = idx;
}

void solve(int l, int r, int L, int R) {
	if (l > r || L > R) return;
	if (l == r) {
		for (int i = L; i <= R; i++) ans[a[i].id] = l;
		return;
	}
	int c1 = 0, c2 = 0, mid = (l + r) >> 1;
	for (int i = l; i <= mid; i++) updateInterval(b[i].l, b[i].r, b[i].p);
	for (int i = L; i <= R; i++) {
		int res = 0;
		for (int j = h[i]; j; j = ne[j]) res += getsum(e[j]);
		if (a[i].p <= res) a1[++c1] = a[i];
		else a[i].p -= res, a2[++c2] = a[i];
	}
	for (int i = l; i <= mid; i++) updateInterval(b[i].l, b[i].r, -b[i].p);
	for (int i = 1; i <= c1; i++) a[L + i - 1] = a1[i];
	for (int i = 1; i <= c2; i++) a[L + c1 + i - 1] = a2[i];
	solve(l, mid, L, L + c1 - 1);
	solve(mid + 1, r, L + c1, R);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> o[i];
		push(o[i], i);
	}
	for (int i = 1; i <= n; i++) cin >> a[i].p, a[i].id = i;
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> b[i].l >> b[i].r >> b[i].p;
	for (int i = 1; i <= k; i++) updateInterval(b[i].l, b[i].r, b[i].p);
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = h[i]; j; j = ne[j]) res += getsum(e[j]);
		cout << i << ": " << res << endl;
		nie[i] = (res < a[i].p);
	}
	for (int i = 1; i <= k; i++) updateInterval(b[i].l, b[i].r, -b[i].p);
	for (int i = 1; i <= n; i++) cout << nie[i] << endl;
	return 0;
}

