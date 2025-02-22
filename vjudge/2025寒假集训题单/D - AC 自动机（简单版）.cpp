#include <iostream>
#include <queue>

using namespace std;

constexpr int N = 1e6 + 10, M = 26;
queue<int> q;
char tempStrMode[N], strMain[N];
int n, fail[N], ch[N][M], val[N], idx, ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", tempStrMode);
		int cur = 0;
		for (int j = 0; tempStrMode[j]; j++) {
			if (!ch[cur][tempStrMode[j] - 'a']) ch[cur][tempStrMode[j] - 'a'] = ++idx;
			cur = ch[cur][tempStrMode[j] - 'a'];
		}
		val[cur]++;
	}
	scanf("%s", strMain);
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
	int cur = 0;
	for (int i = 0; strMain[i]; i++) {
		cur = ch[cur][strMain[i] - 'a'];
		for (int j = cur; j && val[j] != -1; j = fail[j])
			ans += val[j], val[j] = -1;
	}
	printf("%d\n", ans);
	return 0;
}

