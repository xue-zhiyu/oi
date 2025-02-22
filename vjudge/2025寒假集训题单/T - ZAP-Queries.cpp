#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

constexpr int N = 5e4 + 10;
bool book[N];
int primes[N], tot, mu[N], smu[N];

void init() {
	mu[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!book[i]) primes[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot; j++) {
			if (i * primes[j] >= N) break;
			book[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				mu[i * primes[j]] = 0;
				break;
			}
			mu[i * primes[j]] = -mu[i];
		}
	}
	for (int i = 1; i < N; i++) smu[i] = smu[i - 1] + mu[i];
}

int solve(int n, int m) {
	int res = 0;
	for (int l = 1, r; l <= n && l <= m; l = r + 1) {
		r = min((n / l ? n / (n / l) : 0x7fffffffffff), (m / l ? m / (m / l) : 0x7fffffffffff));
		res += (smu[r] - smu[l - 1]) * (n / l) * (m / l);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while (T --> 0) {
		int a, b, d;
		cin >> a >> b >> d;
		cout << solve(a / d, b / d) << endl;
	}
	return 0;
}

