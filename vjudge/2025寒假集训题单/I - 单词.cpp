#include <iostream>
#include <queue>

using namespace std;

constexpr int N = 210, M = 1e6 + 10, K = 26;
queue<int> q;
char strMode[N][M];
int n, fail[M], ch[M][K], cnt[M], val[M], ys[M], ind[M], idx, ans[M];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", strMode[i]);
		int cur = 0;
		for (int j = 0; strMode[i][j]; j++) {
			if (!ch[cur][strMode[i][j] - 'a']) ch[cur][strMode[i][j] - 'a'] = ++idx;
			cur = ch[cur][strMode[i][j] - 'a'];
		}
		if (val[cur]) ys[i] = val[cur];
		else val[cur] = ys[i] = i;
	}
	for (int i = 0; i < K; i++)
		if (ch[0][i])
			q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < K; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				ind[fail[ch[u][i]]]++;
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 0; strMode[i][j]; j++) {
			cur = ch[cur][strMode[i][j] - 'a'];
			cnt[cur]++;
		}
	}
	for (int i = 1; i <= idx; i++)
		if (!ind[i])
			q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!u) break;
		cnt[fail[u]] += cnt[u];
		if (!--ind[fail[u]]) q.push(fail[u]);
		ans[val[u]] += cnt[u];
	}
	for (int i = 1; i <= n; i++) cout << ans[ys[i]] << endl;
	return 0;
}

