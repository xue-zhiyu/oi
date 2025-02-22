#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

constexpr int N = 1e5 + 10;

bool tag[N];
int ch[N][2], fa[N], val[N], sum[N];

int where(int x) { return ch[fa[x]][1] == x; }

bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }

void pushup(int x) { sum[x] = sum[ch[x][0]] ^ val[x] ^ sum[ch[x][1]]; }

void pushd(int x) {
	if (tag[x]) {
		tag[x] = false;
		if (ch[x][0]) swap(ch[ch[x][0]][0], ch[ch[x][0]][1]), tag[ch[x][0]] = !tag[ch[x][0]];
		if (ch[x][1]) swap(ch[ch[x][1]][0], ch[ch[x][1]][1]), tag[ch[x][1]] = !tag[ch[x][1]];
	}
}

void pushdown(int x) {
	if (!isroot(x)) pushdown(fa[x]);
	pushd(x); 
}

void rotate(int x) {
	int y = fa[x], z = fa[fa[x]], chk = where(x);
	if (!isroot(y)) ch[z][ch[z][1] == y] = x;
	ch[y][chk] = ch[x][chk ^ 1], fa[ch[x][chk ^ 1]] = y;
	ch[x][chk ^ 1] = y, fa[y] = x, fa[x] = z;
	pushup(y), pushup(x);
}

void splay(int x) {
	pushdown(x);
	while (!isroot(x)) {
		int y = fa[x];
		if (!isroot(y)) {
			if (where(x) == where(y)) rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
}

void access(int p) {
	int q = 0;
	while (p) {
		splay(p);
		ch[p][1] = q;
		pushup(p);
		q = p, p = fa[p];
	}
}

void beroot(int p) {
	access(p), splay(p);
	swap(ch[p][0], ch[p][1]);
	tag[p] = true;
}

void belink(int x, int y) {
	beroot(x);
	access(y);
	splay(y);
}

int findRoot(int x) {
	access(x), splay(x);
	while (ch[x][0]) x = ch[x][0];
	splay(x);
	return x;
}

void link(int x, int y) {
	if (findRoot(x) != findRoot(y)) beroot(x), fa[x] = y;
}

void cut(int x, int y) {
	belink(x, y);
	if (ch[y][0] == x) ch[y][0] = fa[x] = 0;
}

void update(int x, int y) {
	splay(x);
	val[x] = y;
	pushup(x);
}

int query(int x, int y) {
	belink(x, y);
	return sum[y];
}

int n, m;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i];
	while (m --> 0) {
		int opt, x, y;
		cin >> opt >> x >> y;
		switch (opt) {
			case 0: cout << query(x, y) << endl; break;
			case 1: link(x, y); break;
			case 2: cut(x, y); break;
			case 3: update(x, y); break;
		}
	}
	return 0;
}

