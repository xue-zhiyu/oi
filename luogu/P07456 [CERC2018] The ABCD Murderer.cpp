#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int N = 3e5 + 10, K = 26;

char tempStrMode[N], strMain[N];

bool val[N];
queue<int> que;
int n, m, fail[N], ch[N][K], dep[N], idx, f[N], dis[N];

int main() {
	scanf("%d", &n);
	scanf("%s", strMain);
	m = strlen(strMain);
	for (int i = 1; i <= n; i++) {
		scanf("%s", tempStrMode);
		int cur = 0;
		for (int j = 0; tempStrMode[j]; j++) {
			if (!ch[cur][tempStrMode[j] - 'a']) {
				ch[cur][tempStrMode[j] - 'a'] = ++idx;
				dep[ch[cur][tempStrMode[j] - 'a']] = dep[cur] + 1;
			}
			cur = ch[cur][tempStrMode[j] - 'a'];
			cout << cur;
		}
		cout << endl;
		val[cur] = true;
	}
	for (int i = 0; i < K; i++)
		if (ch[0][i])
			que.push(ch[0][i]);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i < K; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				que.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
	cout << "fail: ";
	for (int i = 0; i <= idx; i++) cout << fail[i] << (i == idx ? '\n' : ' ');
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	int cur = 0;
	for (int i = 1; strMain[i - 1]; i++) {
		cur = ch[cur][strMain[i - 1] - 'a'];
		cout << i << ": " << cur << endl;
		for (int j = cur, k = 0; j; j = fail[j], k++)
			if (val[j]) cout << i << ' ' << j << endl, f[i] = min(f[i], f[i - ] + 1);
	}
	for (int i = 0; i <= m; i++) cout << f[i] << (i == m ? '\n' : ' ');
	return 0;
}

