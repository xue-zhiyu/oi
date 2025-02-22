#include <iostream>
#define int long long
#define endl '\n'

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

constexpr int N = 1e5 + 10, M4 = 2e5 + 10, M = 5e4 + 10;

struct Line {
	double k, b;
} p[N];

double calc(int id, int x) {
	return p[id].k * x + p[id].b;
}

int s[M4], cnt;

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> m;
	while (m --> 0) {
		string opt;
		cin >> opt;
		if (opt == "Project") {
			double s, k;
			cin >> s >> k;
			p[++cnt] = {k, s - k};
			modify(1, 1, M, 1, M, cnt);
		} else {
			int t;
			cin >> t;
			cout << (int)(query(1, 1, M, t).first / 100) << endl;
		}
	}
	return 0;
}

