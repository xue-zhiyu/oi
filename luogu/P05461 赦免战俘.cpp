#include <iostream>

using namespace std;

constexpr int N2 = 1100;
int n, a[N2][N2];

void draw(int dep, int sx, int sy) {
	if (dep == 1) {
		a[sx][sy + 1] = a[sx + 1][sy] = a[sx + 1][sy + 1] = 1;
		return;
	}
	draw(dep - 1, sx + (1 << (dep - 1)), sy);
	draw(dep - 1, sx, sy + (1 << (dep - 1)));
	draw(dep - 1, sx + (1 << (dep - 1)), sy + (1 << (dep - 1)));
}

int main() {
	cin >> n;
	draw(n, 1, 1);
	for (int i = 1; i <= (1 << n); i++)
		for (int j = 1; j <= (1 << n); j++)
			cout << a[i][j] << (j == (1 << n) ? '\n' : ' ');
	return 0;
}

