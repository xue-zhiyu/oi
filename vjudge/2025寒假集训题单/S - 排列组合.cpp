#include <cstring>
#include <iostream>

using namespace std;

const int N = 15, M = 15;
int n, m, a[N], c[N][N], fac[N], fa[M], fb[M], fc[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	c[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++)
			c[i][j] = (j ? c[i - 1][j] + c[i - 1][j - 1] : 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
	fa[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		memset(fb, 0, sizeof(fb));
		memset(fc, 0, sizeof(fc));
		for (int j = 0; j <= a[i]; j++) fb[j] = 1;
		for (int j = 0; j < M; j++)
			for (int k = 0; k <= j; k++)
				fc[j] += c[j][k] * fa[k] * fb[j - k];
		memcpy(fa, fc, sizeof(fa));
	}
	cout << fa[m] << endl;
	return 0;
}

