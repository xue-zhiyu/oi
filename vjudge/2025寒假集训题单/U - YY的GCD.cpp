#include <bitset>
#include <iostream>
#define int long long

using namespace std;

int read() {
	int res = 0; char ch = fgetc(stdin);
	while (ch < '0' || ch > '9') ch = fgetc(stdin);
	while ('0' <= ch && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
	return res;
}

int stk[60], top;

void println(int x) {
	if (!x) return void((fputc('0', stdout), fputc('\n', stdout)));
	while (x) stk[++top] = x % 10, x /= 10;
	while (top) fputc(stk[top--] + '0', stdout);
	fputc('\n', stdout);
}

constexpr int N = 1e7 + 10;
bool book[N];
int primes[N], tot, mu[N], f[N], s[N], ans;

void init() {
	mu[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!book[i]) primes[++tot] = i;
		for (int j = 1; j <= tot; j++) {
			if (i * primes[j]) break;
			book[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				mu[i * primes[j]] = 0;
				break;
			}
			mu[i * primes[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= tot; i++)
		for (int j = primes[i]; j < N; j += primes[i])
			f[j] += mu[j / primes[i]];
	for (int i = 1; i < N; i++) s[i] = s[i - 1] + f[i];
	for (int i = 1; i <= 30; i++) cout << f[i] << (i == 30 ? '\n' : ' ');
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while (T --> 0) {
		int n, m;
		cin >> n >> m;
		ans = 0;
		for (int l = 1, r; l <= n && l <= m; l = r + 1) {
			r = min(n / (n / l), m / (m / l));
			ans += (n / l) * (m / l) * (s[r] - s[l - 1]);
		}
		cout << ans << endl;
	}
	return 0;
}

