#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int N = 2e5 + 10, M = 2e6 + 10, K = 26;
queue<int> q;
vector<int> val[N];
char tempStrMode[N], strMain[M];
int n, fail[N], ch[N][K], idx, ind[N], cnt[N], ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", tempStrMode);
		int cur = 0;
		for (int j = 0; tempStrMode[j]; j++) {
			if (!ch[cur][tempStrMode[j] - 'a']) ch[cur][tempStrMode[j] - 'a'] = ++idx;
			cur = ch[cur][tempStrMode[j] - 'a'];
		}
		val[cur].push_back(i);
	}
	scanf("%s", strMain);
	for (int i = 0; i < K; i++)
		if (ch[0][i])
			q.push(ch[0][i]), ind[0]++;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < K; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				ind[ch[fail[u]][i]]++;
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	int cur = 0;
	for (int i = 0; strMain[i]; i++) {
		cur = ch[cur][strMain[i] - 'a'];
		cnt[cur]++;
	}
	for (int i = 0; i <= idx; i++)
		if (!ind[i])
			q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		cnt[fail[u]] += cnt[u];
		if (!--ind[fail[u]]) q.push(fail[u]);
		for (int i : val[u]) ans[i] += cnt[u];
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}

