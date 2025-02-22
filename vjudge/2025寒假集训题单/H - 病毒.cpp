#include <iostream>
#include <queue>

using namespace std;

constexpr int N = 2010, M = 3e4 + 10;
queue<int> q;
bool f[M], book[M], instk[M];
char strMode[M];
int n, fail[M], ch[M][2], idx;

bool dfs(int u) {
	instk[u] = true;
	for (int i = 0; i < 2; i++) {
		if (instk[ch[u][i]]) return true;
		if (book[ch[u][i]] || f[ch[u][i]]) continue;
		book[ch[u][i]] = true;
		if (dfs(ch[u][i])) return true;
	}
	instk[u] = false;
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", strMode);
		int cur = 0;
		for (int j = 0; strMode[j]; j++) {
			if (!ch[cur][strMode[j] - '0']) ch[cur][strMode[j] - '0'] = ++idx;
			cur = ch[cur][strMode[j] - '0'];
		}
		f[cur] = true;
	}
	for (int i = 0; i < 2; i++)
		if (ch[0][i])
			q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 2; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				f[ch[u][i]] = f[ch[u][i]] || f[fail[ch[u][i]]];
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	if (dfs(0)) puts("TAK");
	else puts("NIE");
	return 0;
}

