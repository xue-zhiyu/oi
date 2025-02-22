#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

constexpr int N = 2e5 + 10, N2 = 4e5 + 10;
bool ans1[N], ans2[N];
int n, l[N], r[N], id[N], a[N2], c[N2], len;

int lowbit(int x) {
	return x & -x;
}

void update(int k, int x) {
	while (k <= len) {
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

int main() {
	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i], a[2 * i - 1] = l[i], a[2 * i] = r[i], id[i] = i;
	sort(a + 1, a + 2 * n + 1);
	len = unique(a + 1, a + 2 * n + 1) - a - 1;
	for (int i = 1; i <= n; i++) l[i] = lower_bound(a + 1, a + len + 1, l[i]) - a, r[i] = lower_bound(a + 1, a + len + 1, r[i]) - a;
	sort(id + 1, id + n + 1, [&](int i, int j) { return l[i] == l[j] ? r[i] > r[j] : l[i] < l[j]; });
	for (int i = n; i >= 1; i--) {
		ans1[id[i]] = (getsum(r[id[i]]) - getsum(l[id[i]] - 1)) > 0;
		update(r[id[i]], 1);
	}
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) {
		ans2[id[i]] = (getsum(len) - getsum(r[id[i]] - 1)) > 0;
		update(r[id[i]], 1);
	}
	for (int i = 1; i <= n; i++) cout << ans1[i] << (i == n ? '\n' : ' ');
	for (int i = 1; i <= n; i++) cout << ans2[i] << (i == n ? '\n' : ' ');
	return 0;
}

