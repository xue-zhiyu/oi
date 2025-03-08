#include <cstring>
#include <iostream>
#define int long long

using namespace std;

constexpr int N = 1e5 + 10, M = 2e6 + 1e5 + 10, K = 2.6e6 + 10, mod = 1e9 + 7;
char dat[M], *s[N];
int n, m, top, pos[N], val[K], ch[K][26], fa[K], idx = 1, ans1, ans2;

int pi(int l, int r) {
	int res = 1;
	for (int i = l; i <= r; i++) res = res * i % mod;
	return res;
}

int calc(int n, int m) {
	if (n < m) return 0;
	return pi(n - m + 1, n) * pi(1, m) % mod;
}

void dfs(int u, int dep) {
	int sum = 0, old = ans2;
	for (int i = 0; i < 26; i++) {
		if (ch[u][i]) {
			dfs(ch[u][i], dep + 1);
			for (int k = 2; k <= m; k++) {
				for (int j = 1; j < k; j++) {
					int fa = i, fb = k - j;
					if (fa <= sum && fb <= val[ch[u][i]]) {
						cout << u << ": " << k << ' ' << fa << ' ' << fb << ' ';
						int res = 0;
						ans2 = (ans2 + calc(sum, fa) * calc(val[ch[u][i]], fb) % mod * dep % mod * val[u] % mod) % mod;
						res += calc(sum, fa) * calc(val[ch[u][i]], fb) % mod * dep % mod * val[u] % mod;
						cout << res << endl;
					}
				}
			}
			sum += val[ch[u][i]];
		}
	}
	cout << u << ": " << ans2 - old << endl;
}

signed main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] = dat + top);
		top += strlen(s[i]) + 1;
		int cur = 1;
		for (int j = 0; s[i][j]; j++) {
			if (!ch[cur][s[i][j] - 'a']) fa[ch[cur][s[i][j] - 'a'] = ++idx] = cur;
			cur = ch[cur][s[i][j] - 'a'];
		}
		pos[i] = cur;
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		val[pos[i]] += t;
	}
	for (int i = idx; i != 1; i--) val[fa[i]] = (val[fa[i]] + val[i]) % mod;
	dfs(1, 0);
	cout << ans2 << endl;
	return 0;
}

