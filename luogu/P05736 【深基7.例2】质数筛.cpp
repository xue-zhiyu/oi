#include <bitset>
#include <iostream>

using namespace std;

constexpr int N = 1e5 + 10;
bitset<N> book;
int n, primes[N], tot;

void init() {
	book.set(1);
	for (int i = 2; i < N; i++) {
		if (!book.test(i)) primes[++tot] = i;
		for (int j = 1; j <= tot; j++) {
			if (i * primes[j] >= N) break;
			book.set(i * primes[j]);
			if (i % primes[j] == 0) continue;
		}
	}
}

int main() {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (!book.test(t)) cout << t << ' ';
	}
	return 0;
}

