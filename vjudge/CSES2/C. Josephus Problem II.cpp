#include <cmath>
#include <iostream>

using namespace std;

constexpr int N = 2e5 + 10;
int n, k, c[N], cur = 1;

int lowbit(int x) {
	return x & -x;
}

void init() {
	for (int i = 1; i <= n; i++) c[i] = lowbit(i);
}

void update(int k, int x) {
	while (k <= n) {
		c[k] += x;
		k += lowbit(k);
	}
}

int getkth(int k) {
	int sum = 0, x = 0;
	for (int i = log2(n); ~i; --i) {
		x += 1 << i;
		if (x >= n || sum + c[x] >= k) x -= 1 << i;
		else sum += c[x];
	}
	return x + 1;
}

int main() {
	cin >> n >> k; k++;
	init();
	for (int i = n; i >= 1; i--) {
		cur = (cur - 1 + k - 1) % i + 1;
		int ans = getkth(cur);
		update(ans, -1);
		cout << ans << (i == 1 ? '\n' : ' ');
	}
	return 0;
}

