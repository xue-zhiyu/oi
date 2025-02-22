#include <ctime>
#include <iostream>

using namespace std;

constexpr int n = 10, m = 1e5, q = 1e5, t = 1;

int main() {
	freopen("str.in", "w", stdout);
	srand(time(nullptr));
	for (int i = 0; i < n; i++) putchar(rand() % 26 + 'a');
	putchar('\n');
	for (int i = 0; i < m; i++) putchar(rand() % 26 + 'a');
	printf("\n%d\n", q);
	for (int i = 0; i < q; i++) {
		int len = t;
		for (int j = 0; j < len; j++) putchar(rand() % 26 + 'a');
		putchar('\n');
	}
	return 0;
}

