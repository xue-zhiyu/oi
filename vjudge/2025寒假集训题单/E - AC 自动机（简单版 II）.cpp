#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int N = 160, M = 80, K = 10510, T = 1e6 + 10, C = 26;
char strMode[N][M], strMain[T];
int n, fail[K], ch[K][C], val[K], idx, ans[N];

void push(char str[], int id) {
	int cur = 0;
	for (int i = 0; str[i]; i++) {
		if (!ch[cur][str[i] - 'a']) ch[cur][str[i] - 'a'] = ++idx;
		cur = ch[cur][str[i] - 'a'];
	}
	val[cur] = id;
}

void build() {
	queue<int> q;
	for (int i = 0; i < C; i++)
		if (ch[0][i])
			q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < C; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
}

void solve(char str[]) {
	int cur = 0;
	for (int i = 0; str[i]; i++) {
		cur = ch[cur][str[i] - 'a'];
		for (int j = cur; j; j = fail[j])
			ans[val[j]]++;
	}
}

int main() {
	while ((scanf("%d", &n), n)) {
		memset(fail, 0, sizeof(fail));
		memset(ch, 0, sizeof(ch));
		memset(val, 0, sizeof(val));
		memset(ans, 0, sizeof(ans));
		idx = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s", strMode[i]);
			push(strMode[i], i);
		}
		scanf("%s", strMain);
		build();
		solve(strMain);
		int mxans = 0;
		for (int i = 1; i <= n; i++) mxans = max(mxans, ans[i]);
		cout << mxans << endl;
		for (int i = 1; i <= n; i++)
			if (ans[i] == mxans)
				printf("%s\n", strMode[i]);
	}
	return 0;
}

