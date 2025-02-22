#include <iostream>
#include <vector>
#include <stack>
#define endl '\n'

using namespace std;

class SplayTree {
public:
	void resize(int N) {
		val = vector<int>(N, 0);
		cnt = vector<int>(N, 0);
		siz = vector<int>(N, 0);
		fa = vector<int>(N, 0);
		ch = vector<vector<int>>(N, vector<int>(2, 0));
	}

	void push(int x) {
		if (!root) {
			int tmp = getnode();
			val[tmp] = x, cnt[tmp] = 1;
			pushup(tmp);
			root = tmp;
			return;
		}
		int cur = root, f = 0;
		while (true) {
			if (val[cur] == x) {
				cnt[cur]++;
				pushup(cur);
				pushup(f);
				splay(cur);
				return;
			}
			f = cur;
			cur = ch[cur][val[cur] < x];
			if (!cur) {
				int tmp = getnode();
				val[tmp] = x, cnt[tmp] = 1, fa[tmp] = f, ch[f][val[f] < x] = tot;
				pushup(tmp);
				pushup(f);
				splay(tmp);
				return;
			}
		}
	}

	void del(int x) {
		if (!contains(x)) return;
		getrank(x);
		if (cnt[root] > 1) {
			cnt[root]--;
			pushup(root);
			return;
		}
		if (ch[root][0]) {
			if (ch[root][1]) {
				int cur = root, pre = _getprev();
				fa[ch[cur][1]] = pre;
				ch[pre][1] = ch[cur][1];
				clear(cur);
				pushup(root);
			} else {
				int cur = root;
				root = ch[cur][0];
				fa[root] = 0;
				clear(cur);
			}
		} else {
			if (ch[root][1]) {
				int cur = root;
				root = ch[cur][1];
				fa[root] = 0;
				clear(cur);
			} else {
				clear(root);
				root = 0;
			}
		}
	}

	int getrank(int x) {
		if (!root) return 1;
		int res = 0, cur = root;
		while (true) {
			if (!cur) return res + 1;
			if (x < val[cur]) {
				cur = ch[cur][0];
			} else {
				res += siz[ch[cur][0]];
				if (x == val[cur]) {
					splay(cur);
					return res + 1;
				}
				res += cnt[cur];
				cur = ch[cur][1];
			}
		}
		return inf;
	}

	int getbyrank(int k) {
		if (k < 1 || k > siz[root]) return inf;
		int cur = root;
		while (true) {
			if (k <= siz[ch[cur][0]]) {
				cur = ch[cur][0];
			} else {
				k -= siz[ch[cur][0]] + cnt[cur];
				if (k <= 0) {
					splay(cur);
					return val[cur];
				}
				cur = ch[cur][1];
			}
		}
		return inf;
	}

	int _getprev() {
		if (!root) return inf;
		if (!ch[root][0]) return inf;
		int cur = ch[root][0];
		while (ch[cur][1]) cur = ch[cur][1];
		splay(cur);
		return cur;
	}

	int getprev(int x) {
		push(x);
		int res = _getprev();
		del(x);
		return val[res];
	}

	int _getnext() {
		if (!root) return inf;
		if (!ch[root][1]) return inf;
		int cur = ch[root][1];
		while (ch[cur][0]) cur = ch[cur][0];
		splay(cur);
		return cur;
	}

	int getnext(int x) {
		push(x);
		int res = _getnext();
		del(x);
		return val[res];
	}

	bool contains(int x) {
		return root && getbyrank(getrank(x)) == x;
	}

private:
	const int inf = 0x7fffffff;

	int root, tot;
	vector<int> val, cnt, siz, fa;
	vector<vector<int>> ch;
	stack<int> trush;

	void pushup(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x]; }
	
	int where(int x) { return ch[fa[x]][1] == x; }
	
	void clear(int x) { val[x] = cnt[x] = siz[x] = ch[x][0] = ch[x][1] = fa[x] = 0, trush.push(x); }

	void rotate(int x) {
		int y = fa[x], z = fa[fa[x]], chk = where(x);
		ch[y][chk] = ch[x][chk ^ 1];
		if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
		ch[x][chk ^ 1] = y;
		fa[y] = x;
		fa[x] = z;
		if (z) ch[z][ch[z][1] == y] = x;
		pushup(y);
		pushup(x);
	}

	void splay(int x) {
		for (int f = fa[x]; f = fa[x], f; rotate(x))
			if (fa[f]) rotate(where(f) == where(x) ? f : x);
		root = x;
	}

	int getnode() {
		if (stk.empty()) return ++tot;
		int res = stk.top(); stk.pop();
		return res;
	}
};

template<int N>
class SegsplayTree {
public:

private:
	SegmentTree e[4 * N + 5];
};

