#include <iostream>
#define int long long
#define endl '\n'
#define lson(__x__) ((__x__) << 1)
#define rson(__x__) ((__x__) << 1 | 1)

using namespace std;

constexpr int N = 1e5 + 10, M = 4e5 + 10;
int n, m, mod, a[N], e[M], tagmul[M], tagadd[M];

void pushup(int p) {
	e[p] = (e[lson(p)] + e[rson(p)]) % mod;
}

void pushdown(int p, int l, int r) {
	int mid = (l + r) >> 1;
	e[lson(p)] = (e[lson(p)] * tagmul[p] % mod + (mid - l + 1) * tagadd[p] % mod) % mod;
	e[rson(p)] = (e[rson(p)] * tagmul[p] % mod + (r - mid) * tagadd[p] % mod) % mod;
	tagmul[lson(p)] = tagmul[lson(p)] * tagmul[p] % mod, tagmul[rson(p)] = tagmul[rson(p)] * tagmul[p] % mod;
	tagadd[lson(p)] = (tagadd[lson(p)] * tagmul[p] % mod + tagadd[p]) % mod, tagadd[rson(p)] = (tagadd[rson(p)] * tagmul[p] % mod + tagadd[p]) % mod;
	tagmul[p] = 1, tagadd[p] = 0;
}

void build(int l, int r, int p) {
	if (l == r) {
		e[p] = a[l], tagmul[p] = 1, tagadd[p] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lson(p));
	build(mid + 1, r, rson(p));
	pushup(p);
}

void updatemul(int l, int r, int p, int sl, int sr, int val) {
	if (sl <= l && r <= sr) {
		e[p] = e[p] * val % mod, tagmul[p] = tagmul[p] * val % mod, tagadd[p] = tagadd[p] * val % mod;
		return;
	}
	int mid = (l + r) >> 1;
	updatemul(l, mid, lson(p), sl, sr, val);
	updatemul(mid + 1, r, rson(p), sl, sr, val);
	pushup(p);
}

void updateadd(int l, int r, int p) {
}

