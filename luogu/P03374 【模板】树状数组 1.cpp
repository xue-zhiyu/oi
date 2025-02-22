#include <iostream>

using namespace std;

int read() {
	int res = 0, f = 1; char ch = fgetc(stdin);
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = fgetc(stdin);
	while ('0' <= ch && ch <= '9') res = res * 10 + ch - '0', ch = fgetc(stdin);
	return res * f; 
}

int stk[114], top;

void write(int x) {
	if (!x) {
		fputc('0', stdout);
		return;
	}
	top = 0;
	while (x) {
		stk[++top] = x % 10;
		x /= 10;
	}
	while (top) fputc(stk[top--] + '0', stdout);
}

constexpr int M = 1048576 + 10000;
int n, opts, m, e[M];

void build() {
	for (m = 1; m <= n; m <<= 1);
	for (int i = m + 1; i <= m + n; i++) cin >> e[i];
	for (int i = m - 1; i; i--) e[i] = e[i << 1] + e[i << 1 | 1];
}

void update(int x, int val) {
	x = m + x;
	while (x) {
		e[x] += val;
		x >>= 1;
	}
}

int query(int l, int r) {
	int ans = 0;
	for (l = l + m - 1, r = r + m + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if (~l & 1) ans += e[l ^ 1];
		if (r & 1)  ans += e[r ^ 1];
	}
	return ans;
}

int main() {
	n = read(), opts = read();
	build();
	while (opts --> 0) {
		int opt = read(), a = read(), b = read();
		if (opt == 1) {
			update(a, b);
		} else {
			write(query(a, b));
			fputc('\n', stdout);
		}
	}
	return 0;
}

