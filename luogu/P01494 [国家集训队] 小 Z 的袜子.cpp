#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#define int long long

using namespace std;

struct query {
	int id, l, r;
};

constexpr int N = 5e4 + 10;
query querys[N];
pair<int, int> ans[N];
int n, m, a[N], len, l, r, cnt[N], sum;

void move(int pos, int flag) {
	sum -= cnt[a[pos]] * cnt[a[pos]];
	cnt[a[pos]] += flag;
	sum += cnt[a[pos]] * cnt[a[pos]];
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

pair<int, int> simplition(int a, int b) {
	if (a == 0) return make_pair(0, 1);
	int _gcd = gcd(a, b);
	return make_pair(a / _gcd, b / _gcd);
}

signed main() {
	cin >> n >> m;
	len = pow(n, 0.5);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> querys[i].l >> querys[i].r, querys[i].id = i;
	sort(querys + 1, querys + m + 1, [](query i, query j) { return i.l / len == j.l / len ? i.r < j.r : i.l < j.l; });
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		query& q = querys[i];
		if (q.l == q.r) ans[q.id] = {0, 1};
		while (l > q.l) move(--l, 1);
		while (r < q.r) move(++r, 1);
		while (l < q.l) move(l++, -1);
		while (r > q.r) move(r--, -1);
		ans[q.id] = simplition(sum - (r - l + 1), (r - l + 1) * (r - l));
	}
	for (int i = 1; i <= m; i++) cout << ans[i].first << '/' << ans[i].second << endl;
	return 0;
}

