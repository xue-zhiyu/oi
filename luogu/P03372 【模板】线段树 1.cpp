#include <iostream>
#define int long long

using namespace std;

constexpr int M = 262144 + 1000;
int n, opts, m, e[M], a[M];

void update(int l, int r, int val) {
	int lcnt = 0, rcnt = 0, now = 1;
	for (l = l + m - 1, r = r + m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, now <<= 1) {
		e[l] += val * lcnt, e[r] += val * rcnt;
		if (~l & 1) e[l ^ 1] += val * now, a[l ^ 1] += val, lcnt += now;
		if (r & 1)  e[r ^ 1] += val * now, a[r ^ 1] += val, rcnt += now;
	}
	for (; l; l >>= 1, r >>= 1) e[l] += val * lcnt, e[r] += val * rcnt;
}

int query(int l, int r) {
	int lcnt = 0, rcnt = 0, now = 1, res = 0;
	for (l = l + m - 1, r = r + m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, now <<= 1) {
		res += a[l] * lcnt + a[r] * rcnt;
		if (~l & 1) res += e[l ^ 1], lcnt += now;
		if (r & 1)  res += e[r ^ 1], rcnt += now;
	}
	for (; l; l >>= 1, r >>= 1) res += a[l] * lcnt, res += a[r] * rcnt;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin >> n >> opts;
	for (m = 1; m <= n; m <<= 1);
	for (int i = m + 1; i <= m + n; i++) cin >> e[i];
	for (int i = m - 1; i; i--) e[i] = e[i << 1] + e[i << 1 | 1];
	while (opts --> 0) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			update(l, r, k);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
	return 0;
}

