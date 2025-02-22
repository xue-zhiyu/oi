#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

struct query {
	int id, l, r;
};

constexpr int N = 5e5 + 10;
query querys[N];
int n, a[N], m, ans[N], len, l, r, cnt[N], ansans[N];

void move(int pos, int flag) {
	cnt[pos] += flag;
}

int main() {
	ifstream fin("occur.in", ios_base::in);
	ifstream fout("occur.out", ios_base::in);
	ifstream fans("occur.ans", ios_base::in);
	fin >> n;
	len = sqrt(n);
	for (int i = 1; i <= n; i++) fin >> a[i];
	fin >> m;
	for (int i = 1; i <= m; i++) fin >> querys[i].l >> querys[i].r, querys[i].id = i;
	for (int i = 1; i <= m; i++) fout >> ans[i];
	for (int i = 1; i <= m; i++) fans >> ansans[i];
	sort(querys + 1, querys + m + 1, [](query a, query b) { return a.l / len == b.l / len ? a.r < b.r : a.l < b.l; });
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		query& q = querys[i];
		while (l > q.l) move(a[--l], 1);
		while (r < q.r) move(a[++r], 1);
		while (l < q.l) move(a[l++], -1);
		while (r > q.r) move(a[r--], -1);
		if (cnt[ans[q.id]] != 1 && ansans[q.id] != ans[q.id]) {
			cout << "errat: " << q.id << ", " << ans[q.id] << endl;
			return 0;
		}
	}
	cout << "accept" << endl;
	return 0;
}

