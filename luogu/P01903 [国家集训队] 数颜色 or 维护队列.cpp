#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct query {
	int id, l, r, tick;
};

struct opt {
	int pos, val;
};

constexpr int N = 1.4e5, M = 1e6 + 10;
opt opts[N];
query querys[N];
int n, m, mq, mo, a[N], cnt[M], sum, len, l, r, cur, ans[N];

void movepos(int pos, bool flag) {
	if (flag) {
		if (!cnt[pos]) sum++;
		cnt[pos]++;
	} else {
		cnt[pos]--;
		if (!cnt[pos]) sum--;
	}
}

void movetick(int tick) {
	if (l <= opts[tick].pos && opts[tick].pos <= r) {
		movepos(opts[tick].val, 1);
		movepos(a[opts[tick].pos], 0);
	}
	swap(a[opts[tick].pos], opts[tick].val);
}

int main() {
	cin >> n >> m;
	len = pow(n, 2. / 3);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		char opt;
		int a, b;
		cin >> opt >> a >> b;
		if (opt == 'Q') {
			mq++;
			querys[mq] = {mq, a, b, mo};
		} else {
			mo++;
			opts[mo] = {a, b};
		}
	}
	sort(querys + 1, querys + mq + 1, [](query i, query j) { return i.l / len == j.l / len ? (i.r / len == j.r / len ? i.tick < j.tick : i.r < j.r) : i.l < j.l; });
	l = 1, r = 0, cur = 0;
	for (int i = 1; i <= mq; i++) {
		query& q = querys[i];
		while (r < q.r) movepos(a[++r], 1);
		while (r > q.r) movepos(a[r--], 0);
		while (l > q.l) movepos(a[--l], 1);
		while (l < q.l) movepos(a[l++], 0);
		while (cur < q.tick) movetick(++cur);
		while (cur > q.tick) movetick(cur--);
		ans[q.id] = sum;
	}
	for (int i = 1; i <= mq; i++) cout << ans[i] << endl;
	return 0;
}

