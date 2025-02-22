#include <iostream>
#define int long long

using namespace std;

constexpr int N = 1e5 + 10, M = 110;
int n, m, a[N], b[N], c[M], ans;

int lowbit(int x) {
	return x & -x;
}

void update(int k, int x) {
	while (k < M) {
		c[k] += x;
		k += lowbit(k);
	}
}

int getsum(int k) {
	int res = 0;
	while (k) {
		res += c[k];
		k -= lowbit(k);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) ans += getsum(a[i] - 1), update(a[i], 1);
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= m; i++) {
		int res1 = getsum(100) - getsum(b[i]), res2 = getsum(b[i] - 1);
		ans += min(res1, res2);
		update(b[i], 1);
	}
	cout << ans << endl;
	return 0;
}

