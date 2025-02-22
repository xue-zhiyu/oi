#include <cstring>
#include <iostream>
#include <queue>
#define int long long
#define endl '\n'

using namespace std;

constexpr int N = 25, M = 55, K = 26, LS = 25, LT = 2e6 + 10;
queue<int> que;
bool f[LT], val[N];
char tempStrMode[LS], strMain[LT];
int n, m, k, fail[N * LS], ch[N * LS][K], dep[N * LS], idx;

signed main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", tempStrMode);
		int cur = 0;
		for (int j = 0; tempStrMode[j]; j++) {
			if (!ch[cur][tempStrMode[j] - 'a']) dep[ch[cur][tempStrMode[j] - 'a'] = ++idx] = dep[cur] + 1;
			cur = ch[cur][tempStrMode[j] - 'a'];
		}
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
	while (m --> 0) {
		scanf("%s", strMain);
		k = strlen(strMain);
		f[0] = true;
		for (int i = 1; i <= k; i++) f[i] = false;
		int cur = 0;
		for (int i = 1; i <= k; i++) {
			cur = ch[cur][strMain[i - 1] - 'a'];
			for (int j = cur; j; j = fail[j])
				if (val[j]) f[i] = f[i] || f[i - dep[j]];
		}
		int ans = k;
		for (; !f[ans]; ans--);
		printf("%lld\n", ans);
	}
	return 0;
}

