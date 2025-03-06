#include <iostream>
#include <unordered_map>

using namespace std;

using ll = long long;

constexpr int N = 1.7e6 + 10;

bool book[N];
int primes[N], tot;
ll mu[N], phi[N];

int n;
unordered_map<int, ll> mpmu, mpphi;

void init() {
	mu[1] = phi[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!book[i]) primes[++tot] = i, mu[i] = -1, phi[i] = i - 1;
		for (int j = 1; j <= tot; j++) {
			if (i * 1ll * primes[j] >= N) break;
			book[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				mu[i * primes[j]] = 0;
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			}
			mu[i * primes[j]] = -mu[i];
			phi[i * primes[j]] = phi[i] * phi[primes[j]];
		}
	}
	for (int i = 1; i < N; i++) mu[i] += mu[i - 1], phi[i] += phi[i - 1];
}

ll solvemu(int m) {
	if (m < N) return mu[m];
	if (mpmu.count(m)) return mpmu[m];
	ll res = 1;
	for (ll l = 2, r; l <= m; l = r + 1) {
		r = m / (m / l);
		res -= solvemu(m / l) * (r - l + 1);
	}
	return mpmu[m] = res;
}

ll solvephi(int m) {
	if (m < N) return phi[m];
	if (mpphi.count(m)) return mpphi[m];
	ll res = m * 1ll * (m * 1ll + 1) / 2;
	for (ll l = 2, r; l <= m; l = r + 1) {
		r = m / (m / l);
		res -= solvephi(m / l) * (r - l + 1);
	}
	return mpphi[m] = res;
}

int main() {
	init();
	int T;
	cin >> T;
	while (T --> 0) {
		cin >> n;
		cout << solvephi(n) << ' ' << solvemu(n) << endl;
	}
	return 0;
}

