#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct query {
	int id, l, r;
};

constexpr int N = 5e4 + 10;
query querys[N];
int n, m, k, len, a[N], cnt[N], sum, l, r, ans[N];

void move(int pos, bool flag) {
	if (flag) {
		sum -= cnt[a[pos]] * cnt[a[pos]];
		cnt[a[pos]]++;
		sum += cnt[a[pos]] * cnt[a[pos]];
	} else {
		sum -= cnt[a[pos]] * cnt[a[pos]];
		cnt[a[pos]]--;
		sum += cnt[a[pos]] * cnt[a[pos]];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	len = sqrt(n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> querys[i].l >> querys[i].r, querys[i].id = i;
	sort(querys + 1, querys + m + 1, [](query i, query j) { return i.l / len == j.l / len ? i.r < j.r : i.l < j.l; });
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		query& q = querys[i];
		while (l > q.l) move(--l, 1);
		while (r < q.r) move(++r, 1);
		while (l < q.l) move(l++, 0);
		while (r > q.r) move(r--, 0);
		ans[q.id] = sum;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}

