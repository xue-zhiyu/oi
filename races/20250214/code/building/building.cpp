#include <bitset>
#include <iostream>
#define solv(_A_, _B_, _C_) { f[_A_][_B_].set(_C_); print(_A_); fputc(' ', stdout); print(_B_); fputc(' ', stdout); print(_C_); fputc('\n', stdout); n--; }

using namespace std;

int read() {
	int res = 0; char ch = fgetc(stdin);
	while (ch < '0' || ch > '9') ch = fgetc(stdin);
	while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = fgetc(stdin);
	return res;
}

int stk[20], top;

void print(int x) {
	if (!x) {
		fputc('0', stdout);
		return;
	}
	while (x) stk[++top] = x % 10, x /= 10;
	while (top) fputc(stk[top--] + '0', stdout);
}

constexpr int N = 170;
int n, m;
bitset<N> f[N][N];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= m && n >= 6; i++)
		for (int j = 1; j <= m && n >= 6; j++)
			for (int k = 1; k <= m && n >= 6; k++)
				if (i != j && i != k && j != k)
					if (!f[i][j].test(k)) {
						solv(i, j, k) solv(i, k, j) solv(j, i, k) solv(j, k, i) solv(k, i, j) solv(k, j, i)
					}
	for (int i = 1; i <= m && n >= 3; i++)
		for (int j = 1; j <= m && n >= 3; j++)
			if (i != j)
				if (!f[i][i].test(j) && !f[i][j].test(i) && !f[j][i].test(i)) {
					solv(i, i, j) solv(i, j, i) solv(j, i, i)
				}
	for (int i = 1; n; i++) solv(i, i, i);
	return 0;
}

