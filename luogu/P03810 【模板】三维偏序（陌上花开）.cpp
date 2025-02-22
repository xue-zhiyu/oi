#include <algorithm>
#include <iostream>

using namespace std;

int read() {
	int res = 0; char ch = fgetc(stdin);
	while (ch < '0' || ch > '9') ch = fgetc(stdin);
	while ('0' <= ch && ch <= '9') res = res * 10 + ch - '0', ch = fgetc(stdin);
	return res; 
}

int stk[114], top;

void write(int x) {
	if (!x) {
		fputc('0', stdout);
		return;
	}
	top = 0;
	while (x) {
		stk[++top] = x % 10;
		x /= 10;
	}
	while (top) fputc(stk[top--] + '0', stdout);
}

constexpr int K = 3, N = 1e5 + 10;

class Position {
public:
	Position() {
		for (int i = 0; i < K; i++) dat[i] = 0;
	}

	Position(initializer_list<int> pos) {
		auto it = pos.begin();
		for (int i = 0; i < K; i++, it++) dat[i] = *it;
	}

	Position(const Position& other) {
		for (int i = 0; i < K; i++) dat[i] = other.dat[i];
	}

	const int& operator[](int index) const {
		return dat[index];
	}

	int& operator[](int index) {
		return dat[index];
	}

	Position& operator=(const Position& other) {
		for (int i = 0; i < K; i++) dat[i] = other.dat[i];
		return *this;
	}

	bool operator==(const Position& other) const {
		for (int i = 0; i < K; i++)
			if (dat[i] != other.dat[i])
				return false;
		return true;
	}

private:
	int dat[K];
};

bool contains(const Position& lpos, const Position& rpos, const Position& pos) {
	bool flag = true;
	for (int i = 0; i < K; i++) flag = flag && (lpos[i] <= pos[i] && pos[i] <= rpos[i]);
	return flag;
}

bool contains(const Position& lpos, const Position& rpos, const Position& qlpos, const Position& qrpos) {
	bool flag = true;
	for (int i = 0; i < K; i++) flag = flag && (lpos[i] <= qlpos[i] && qrpos[i] <= rpos[i]);
	return flag;
}

bool notintersect(const Position& lpos, const Position& rpos, const Position& qlpos, const Position& qrpos) {
	bool flag = false;
	for (int i = 0; i < K; i++) flag = flag || (qrpos[i] < lpos[i] || qlpos[i] > rpos[i]);
	return flag;
}

struct Node {
	int val;
	Position pos;
	int sum, lson, rson, fg;
	Position lpos, rpos;
} tree[N];

void pushup(int x) {
	tree[x].sum = tree[tree[x].lson].sum + tree[tree[x].rson].sum + tree[x].val;
	tree[x].lpos = tree[x].rpos = tree[x].pos;
	if (tree[x].lson) for (int i = 0; i < K; i++) tree[x].lpos[i] = min(tree[x].lpos[i], tree[tree[x].lson].lpos[i]), tree[x].rpos[i] = max(tree[x].rpos[i], tree[tree[x].lson].rpos[i]);
	if (tree[x].rson) for (int i = 0; i < K; i++) tree[x].lpos[i] = min(tree[x].lpos[i], tree[tree[x].rson].lpos[i]), tree[x].rpos[i] = max(tree[x].rpos[i], tree[tree[x].rson].rpos[i]);
}

int idx, root;
int n, k, f[N];
Position poses[N];

int build(int l, int r, int curfg) {
	if (l > r) return 0;
	int x = ++idx;
	if (l == r) {
		tree[x].val = 1;
		tree[x].pos = poses[l];
		tree[x].lson = tree[x].rson = 0;
		pushup(x);
		return x;
	}
	int mid = (l + r + 1) >> 1;
	nth_element(poses + l, poses + mid, poses + r + 1, [&](const Position& i, const Position& j) { return i[curfg] < j[curfg]; });
	tree[x].val = 1;
	tree[x].pos = poses[mid];
	tree[x].lson = build(l, mid - 1, (curfg + 1) % K);
	tree[x].rson = build(mid + 1, r, (curfg + 1) % K);
	pushup(x);
	return x;
}

int _query(int cur, Position& lpos, Position& rpos) {
	if (!cur) return 0;
	if (contains(lpos, rpos, tree[cur].lpos, tree[cur].rpos)) return tree[cur].sum;
	if (notintersect(lpos, rpos, tree[cur].lpos, tree[cur].rpos)) return 0;
	int ans = 0;
	if (contains(lpos, rpos, tree[cur].pos)) ans += tree[cur].val;
	ans += _query(tree[cur].lson, lpos, rpos);
	ans += _query(tree[cur].rson, lpos, rpos);
	return ans;
}

int query(Position lpos, Position rpos) {
	return _query(root, lpos, rpos);
}

int main() {
	freopen("P3810_5.in", "r", stdin);
	freopen("P3810_5.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= n; i++) poses[i][0] = read(), poses[i][1] = read(), poses[i][2] = read();
	root = build(1, n, 0);
	for (int i = 1; i <= n; i++) {
		f[query({1, 1, 1}, poses[i])]++;
	}
	for (int i = 1; i <= n; i++) {
		write(f[i]);
		fputc('\n', stdout);
	}
	return 0;
}

