#include <ctime>
#include <iostream>

using namespace std;

char buf[1 << 21], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}

constexpr int N = 1e7 + 10;
int n, m, a[N];
unsigned int h1[N];
unsigned long long h2[N], h3[N], h4[N];

int main() {
	srand(time(nullptr));
	int w = ((unsigned long long) (rand())) * rand() * rand() * rand();
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), h1[i] = h1[i - 1] ^ a[i], h2[i] = h2[i - 1] + a[i], h3[i] = h3[i - 1] + (a[i] ^ w), h4[i] = h4[i - 1] ^ (a[i] + w);
	while (m --> 0) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		if ((h1[r1] ^ h1[l1 - 1]) != (h1[r2] ^ h1[l2 - 1])) fputs("No\n", stdout);
		else if ((h2[r1] - h2[l1 - 1]) != (h2[r2] - h2[l2 - 1])) fputs("No\n", stdout);
		else if ((h3[r1] - h3[l1 - 1]) != (h3[r2] - h3[l2 - 1])) fputs("No\n", stdout);
		else if ((h4[r1] ^ h4[l1 - 1]) != (h4[r2] ^ h4[l2 - 1])) fputs("No\n", stdout);
		else fputs("Yes\n", stdout);
	}
	return 0;
}

