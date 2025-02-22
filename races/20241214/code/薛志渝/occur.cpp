#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

FILE *fin, *fout;

int read() {
	int res = 0;
	char ch = fgetc(fin);
	while (ch < '0' || '9' < ch) ch = fgetc(fin);
	while ('0' <= ch && ch <= '9') res = res * 10 + ch - '0', ch = fgetc(fin);
	return res;
}

int stk[20], top;

void write(int x) {
	if (x == 0) {
		fputc('0', fout);
		return;
	}
	top = 0;
	while (x) {
		stk[++top] = x % 10;
		x /= 10;
	}
	while (top) fputc(stk[top--] + '0', fout);
}

struct query {
	int id, l, r;
};

constexpr int N = 5e5 + 10, K = 20;
query querys[N];
int n, a[N], m, len, l, r, cnt[N], ans[N], c[N];

int getans() {
	for (int i = 0; i <= N / len; i++) {
		if (c[i]) {
			int res = i * len;
			while (cnt[res + 1] != 1) res++;
			return res + 1;
		}
	}
	return 0;
}

void move(int pos, bool flag) {
	if (flag) {
		if (cnt[pos] == 1) c[pos / len]--;
		cnt[pos]++;
		if (cnt[pos] == 1) c[pos / len]++;
	} else {
		if (cnt[pos] == 1) c[pos / len]--;
		cnt[pos]--;
		if (cnt[pos] == 1) c[pos / len]++;
	}
}

int main() {
	fin = fopen("occur.in", "r");
	fout = fopen("occur.out", "w");
	n = read();
	len = sqrt(n);
	for (int i = 1; i <= n; i++) a[i] = read();
	m = read();
	for (int i = 1; i <= m; i++) querys[i].l = read(), querys[i].r = read(), querys[i].id = i;
	sort(querys + 1, querys + m + 1, [](query a, query b) { return a.l / len == b.l / len ? (a.r == b.r ? false : ((a.l / len) & 1) ^ (a.r < b.r)) : a.l < b.l; });
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		query& q = querys[i];
		while (l > q.l) move(a[--l], 1);
		while (r < q.r) move(a[++r], 1);
		while (l < q.l) move(a[l++], 0);
		while (r > q.r) move(a[r--], 0);
		ans[q.id] = getans();
	}
	for (int i = 1; i <= m; i++) {
		write(ans[i]);
		fputc('\n', fout);
	}
	fclose(fout);
	fclose(fin);
	return 0;
}

