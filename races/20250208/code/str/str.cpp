/*
1pt~40pts: O(|S0|*(2^m)+\sum |Ti|)
41pts~60pts: O(|S0|+m)
60pts
*/
#include <cstring>
#include <iostream>
#include <queue>
#define int long long

using namespace std;

constexpr int N = 15, M = 1e5 + 10, K = 26, T = 3e5 + 10, mod = 1e9 + 7;
queue<int> que;
char s[N], opts[M], tmp[M];
int n, m, q, yxq, fail[T], ch[T][K], val[T], cnt[T], ind[T], idx, pow2[M], ans[M], ysans[M], ansOfAloneChars[K];

int solveAloneChar(char ch) {
	int res = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == ch)
			res = (res + pow2[m]) % mod;
	for (int i = 0; i < m; i++)
		if (opts[i] == ch)
			res = (res + pow2[m - i - 1]) % mod;
	return res;
}

int dfscur = 0;

void dfs(int dep) {
	if (dep) {
		dfs(dep - 1);
		dfscur = ch[dfscur][opts[dep - 1] - 'a'];
		cnt[dfscur] = (cnt[dfscur] + 1) % mod;
		dfs(dep - 1);
	} else {
		for (int i = 0; s[i]; i++) {
			dfscur = ch[dfscur][s[i] - 'a'];
			cnt[dfscur] = (cnt[dfscur] + 1) % mod;
		}
	}
}

signed main() {
	freopen("str.in", "r", stdin);
	freopen("str.out", "w", stdout);
	pow2[0] = 1;
	for (int i = 1; i < M; i++) pow2[i] = (pow2[i - 1] << 1) % mod;
	scanf("%s", s);
	n = strlen(s);
	scanf("%s", opts);
	m = strlen(opts);
	for (int i = 0; i < K; i++) ansOfAloneChars[i] = solveAloneChar(i + 'a');
	scanf("%lld", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%s", tmp);
		if (!tmp[1]) {
			ans[i] = ansOfAloneChars[tmp[0] - 'a'];
			ysans[i] = i;
		} else {
			int cur = 0;
			for (int i = 0; tmp[i]; i++) {
				if (!ch[cur][tmp[i] - 'a']) ch[cur][tmp[i] - 'a'] = ++idx;
				cur = ch[cur][tmp[i] - 'a'];
			}
			if (val[cur]) ysans[i] = val[cur];
			else val[cur] = ysans[i] = i;
			yxq++;
		}
	}
	if (!yxq) {
		for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
		return 0;
	}
	for (int i = 0; i < K; i++)
		if (ch[0][i])
			que.push(ch[0][i]);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i < K; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				ind[ch[fail[u]][i]]++;
				que.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	dfs(m);
	for (int i = 1; i <= idx; i++)
		if (!ind[i])
			que.push(i);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		if (!u) break;
		cnt[fail[u]] = (cnt[fail[u]] + cnt[u]) % mod;
		que.push(fail[u]);
		ans[val[u]] = cnt[u];
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[ysans[i]]);
	return 0;
}

