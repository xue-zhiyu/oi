#include <iostream>
#define int long long

using namespace std;

constexpr double eps = 1e-8;

int cmp(double a, double b) {
	if (a - b > eps) return 1;
	if (b - a > eps) return -1;
	return 0;
}

using pdi = pair<double, int>;

pdi pmax(pdi a, pdi b) {
	if (cmp(a.first, b.first) == -1) return b;
	if (cmp(a.first, b.first) == 1) return a;
	return a.second < b.second ? a : b;
}

constexpr int N = 1e5 + 10, M4 = 1.6e5 + 10, mod1 = 39989, mod2 = 1e9;

struct Line {
	double k, b;
} p[N];

double calc(int id, int x) {
	return p[id].k * x + p[id].b;
}

int s[M4], cnt;

void pushLine(int x1, int y1, int x2, int y2) {
	if (x1 == x2) p[++cnt] = {0., 1. * max(y1, y2)};
	else p[++cnt] = {1.0 * (y2 - y1) / (x2 - x1), y1 - 1.0 * (y2 - y1) / (x2 - x1) * x1};
}

void modify_upd(int cur, int l, int r, int u) {
	int &v = s[cur], mid = (l + r) >> 1;
	int bmid = cmp(calc(u, mid), calc(v, mid));
	if (bmid == 1 || (!bmid && u < v)) swap(u, v);
	int bl = cmp(calc(u, l), calc(v, l)), br = cmp(calc(u, r), calc(v, r));
	if (bl == 1 || (!bl && u < v)) modify_upd(cur << 1, l, mid, u);
	if (br == 1 || (!br && u < v)) modify_upd(cur << 1 | 1, mid + 1, r, u);
}

void modify(int cur, int l, int r, int ll, int lr, int u) {
	if (ll <= l && r <= lr) {
		modify_upd(cur, l, r, u);
		return;
	}
	int mid = (l + r) >> 1;
	if (ll <= mid) modify(cur << 1, l, mid, ll, lr, u);
	if (lr > mid)  modify(cur << 1 | 1, mid + 1, r, ll, lr, u);
}

pdi query(int cur, int l, int r, int pos) {
	if (r < pos || pos < l) return make_pair(0., 0);
	int mid = (l + r) >> 1;
	double res = calc(s[cur], pos);
	if (l == r) return make_pair(res, s[cur]);
	return pmax(make_pair(res, s[cur]), pmax(query(cur << 1, l, mid, pos), query(cur << 1 | 1, mid + 1, r, pos)));
}

signed main() {
	int n, lans = 0;
	cin >> n;
	while (n --> 0) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1 = (x1 + lans - 1 + mod1) % mod1 + 1;
			x2 = (x2 + lans - 1 + mod1) % mod1 + 1;
			y1 = (y1 + lans - 1 + mod2) % mod2 + 1;
			y2 = (y2 + lans - 1 + mod2) % mod2 + 1;
			if (x1 > x2) swap(x1, x2), swap(y1, y2);
			pushLine(x1, y1, x2, y2);
			modify(1, 1, mod1, x1, x2, cnt);
		} else {
			int x;
			cin >> x;
			x = (x + lans - 1 + mod1) % mod1 + 1;
			cout << (lans = query(1, 1, mod1, x).second) << endl;
		}
	}
	return 0;
}

