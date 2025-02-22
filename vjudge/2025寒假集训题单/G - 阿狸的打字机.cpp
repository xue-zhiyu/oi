#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

constexpr int N = 1e5 + 10, M = 26;

template<typename T>
struct lists {
	T e[N];
	int h[N], ne[N], idx;

	lists() {
		idx = 0;
		for (int i = 0; i < N; i++) h[i] = 0;
	}
	
	void push(int u, T dat) {
		++idx;
		e[idx] = dat;
		ne[idx] = h[u];
		h[u] = idx;
	}

	void foreach(int u, function<void(T)> func) {
		for (int i = h[u]; i; i = ne[i]) func(e[i]);
	}
};

struct BIT {
	int c[N];

	int lowbit(int x) {
		return x & -x;
	}

	void update(int k, int x) {
		while (k < N) {
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
};

struct query {
	int a, id;
};

BIT bit;
lists<int> g;
lists<query> querys;
queue<int> q;
char opts[N];
int n, m, k, fail[N], fa[N], ch[N][M], val[N], idx, dfnl[N], dfnr[N], curdfn, ans[N];

void dfs(int u) {
	dfnl[u] = dfnr[u] = ++curdfn;
	g.foreach(u, [&](int v) {
		dfs(v);
		dfnr[u] = max(dfnr[u], dfnr[v]);
	});
}

int main() {
	scanf("%s", opts + 1); n = strlen(opts + 1);
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (opts[i] == 'B') {
			cur = fa[cur];
		} else if (opts[i] == 'P') {
			val[++k] = cur;
		} else {
			if (!ch[cur][opts[i] - 'a']) fa[ch[cur][opts[i] - 'a'] = ++idx] = cur;
			cur = ch[cur][opts[i] - 'a'];
		}
	}
	for (int i = 0; i < M; i++)
		if (ch[0][i])
			q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < M; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	for (int i = 1; i <= idx; i++) g.push(fail[i], i);
	dfs(0);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		querys.push(b, {a, i});
	}
	cur = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		if (opts[i] == 'P') {
			querys.foreach(++j, [&](query t) { ans[t.id] = bit.getsum(dfnr[val[t.a]]) - bit.getsum(dfnl[val[t.a]] - 1); /* cout << "ans " << t.a << "-" << t.id << ": [" << dfnl[val[t.a]] << ", " << dfnr[val[t.a]] << "]  " << ans[t.id] << endl; */});
		} else if (opts[i] == 'B') {
			bit.update(dfnl[cur], -1);
			cur = fa[cur];
		} else {
			cur = ch[cur][opts[i] - 'a'];
			bit.update(dfnl[cur], 1);
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}

