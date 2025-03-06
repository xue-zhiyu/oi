#include <iostream>
#define endl '\n'

using namespace std;

using ll = long long;

constexpr int N = 1e7 + 10;

bool book[N];
int primes[N], tot, mu[N], s[N];

ll ans;
int n, m;

void init() {
	mu[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!book[i]) primes[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot; j++) {
			if (i * 1ll * primes[j] > N) break;
			book[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				mu[i * primes[j]] = 0;
				break;
			}
			mu[i * primes[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= tot; i++)
		for (int j = 1; j * 1ll * primes[i] < N; j++)
			s[j * primes[i]] += mu[j];
	for (int i = 1; i < N; i++) s[i] += s[i - 1];
}

int main() {
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
			ans += (n / l) * 1ll * (m / l) * (s[r] - s[l - 1]);
		}
		cout << ans << endl;
	}
	return 0;
}

