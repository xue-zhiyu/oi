#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct query {
	int id, l, r;
};

constexpr int N = 3e4 + 10, M = 1e6 + 10, Q = 2e5 + 10;
query querys[Q];
int n, q, a[N], len, cnt[M], sum, ans[Q];

void move(int pos, bool flag) {
	if (flag) {
		if (!cnt[a[pos]]) sum++;
		cnt[a[pos]]++;
	} else {
		cnt[a[pos]]--;
		if (!cnt[a[pos]]) sum--;
	}
}

int main() {
	cin >> n;
	len = sqrt(n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	for (int i = 1; i <= q; i++) cin >> querys[i].l >> querys[i].r, querys[i].id = i;
	sort(querys + 1, querys + q + 1, [](query i, query j) { return i.l / len == j.l / len ? i.r < j.r : i.l < j.l; });
	int l = 1, r = 0;
	for (int i = 1; i <= q; i++) {
		query& q = querys[i];
		while (l > q.l) move(--l, 1);
		while (r < q.r) move(++r, 1);
		while (l < q.l) move(l++, 0);
		while (r > q.r) move(r--, 0);
		ans[q.id] = sum;
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}

