#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#define space fputc(' ', stdout)
#define endl fputc('\n', stdout)
#define int long long

using namespace std;

mt19937_64 rd(time(nullptr));

int stk[50], top;

void write(int x) {
	if (!x) {
		fputc('0', stdout);
		return;
	}
	while (x) {
		stk[++top] = x % 10;
		x /= 10;
	}
	while (top) fputc(stk[top--] + '0', stdout);
}

int getint(int l, int r) {
	return rd() % (r - l + 1) + l;
}

constexpr int N = 1e7, M = 1e9;
int a[N + 10], b[N + 10], id[N + 10], k = 20;

signed main() {
	for (int cur = 19; cur <= 20; cur++) {
		cerr << "At: " << cur << "\r\n" << flush;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(id, 0, sizeof(id));
		freopen("galaseek.in", "w", stdout);
		int n = N, m = N;
		write(n), space, write(m), endl;
		int len = getint(1, n / 10);
		int l1 = getint(1, n - len - len - len), l2 = getint(l1 + len + 1, n - len - len), l3 = getint(l2 + len + 1, n - len);
		int r1 = l1 + len - 1, r2 = l2 + len - 1, r3 = l3 + len - 1, id1 = getint(1, m - 10), id2 = getint(id1 + 1, m - 5), id3 = getint(id2 + 1, m);
		for (int i = 1; i <= len; i++) a[i] = getint(1, M), id[i] = i;
		random_shuffle(id + 1, id + len + 1);
		for (int i = l1; i <= r1; i++) b[i] = a[id[i]];
		random_shuffle(id + 1, id + len + 1);
		for (int i = l2; i <= r2; i++) b[i] = a[id[i]];
		random_shuffle(id + 1, id + len + 1);
		for (int i = l3; i <= r3; i++) b[i] = a[id[i]];
		for (int i = 1; i <= n; i++) {
			if (b[i]) {
				write(b[i]), space;
			} else {
				write(getint(1, M)), space;
			}
		}
		endl;
		for (int i = 1; i <= m; i++) {
			if (i == id1) {
				write(l1), space, write(r1), space;
				write(l2), space, write(r2), endl;
			} else if (i == id2) {
				write(l1), space, write(r1), space;
				write(l3), space, write(r3), endl;
			} else if (i == id3) {
				write(l2), space, write(r2), space;
				write(l3), space, write(r3), endl;
			} else if (getint(1, 2) == 1) {
				write(getint(1, n / 5)), space, write(getint(n - n / 5, n)), space;
				write(getint(1, n / 5)), space, write(getint(n - n / 5, n)), endl;
			} else {
				int len = getint(1, n);
				int l1 = getint(1, n - len + 1), l2 = getint(1, n - len + 1);
				write(l1), space, write(l1 + len - 1), space;
				write(l2), space, write(l2 + len - 1), endl;
			}
		}
		cerr << "here\n";
		freopen("CON", "w", stdout);
		system("std.exe");
		system(("rename galaseek.in galaseek" + to_string(cur) + ".in").c_str());
		system(("rename galaseek.out galaseek" + to_string(cur) + ".out").c_str());
	}
	return 0;
}

