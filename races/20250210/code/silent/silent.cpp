#include <iostream>

using namespace std;

constexpr int N = 2e7 + 10, mod = 1e9 + 7;
char s[N];
int n, m, k, a[N], l, r, ans;

int main() {
	int T;
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d%d%s", &n, &k, s + 1);
		m = n - k + 1;
		for (int i = 1; i <= m; i++) a[i] = 0;
		l = 1, r = m;
		for (int i = 1, j = 1; i <= m; i++) {
			if (s[i] != s[i + k]) {
				if (i == m || s[i + k] < s[i]) {
					for (int k = j; k <= i; k++) a[l++] = k;
				} else {
					for (int k = i; k >= j; k--) a[r--] = k;
				}
				j = i + 1;
			}
		}
		ans = 0;
		for (int i = 1; i <= m; i++) ans = (ans * 1ll + i * 1ll * a[i] % mod) % mod;
		cout << ans << endl;
	}
	return 0;
}

