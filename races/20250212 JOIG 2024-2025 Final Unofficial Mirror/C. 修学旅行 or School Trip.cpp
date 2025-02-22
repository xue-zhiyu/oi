#include <iostream>

using namespace std;

constexpr int N = 20, M = 6e5 + 10;
char s[M];
int n, m, q, cnt[N][M];

bool check(int x) {
	return x == 0b011 || x == 0b101 || x == 0b110 || x == 0b111;
}

int main() {
	scanf("%d%d%s", &n, &q, s);
	m = 1;
	for (int i = 0; i < n; i++, m *= 3);
	for (int i = 0; i < m; i++) cnt[0][i] = (s[i] - 'A') * 3;
	for (int i = m, j = 0; i > 1; i /= 3, j++)
		for (int k = 0; k < i; k++)
			if (check(cnt[j][k]))
				cnt[j + 1][k / 3] |= (1 << (k % 3));
	while (q --> 0) {
		int p;
		cin >> p; p--;
		cnt[0][p] = 3 - cnt[0][p];
		for (int j = 0; j < n; j++, p /= 3) {
			if (check(cnt[j][p])) cnt[j + 1][p / 3] |= (1 << (p % 3));
			else cnt[j + 1][p / 3] &= (~(1 << (p % 3)));
		}
		cout << char(check(cnt[n][0]) + 'A') << endl;
	}
	return 0;
}

