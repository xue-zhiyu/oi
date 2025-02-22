#include <cstring>
#include <iostream>
#define int long long

using namespace std;

const int N = 110;
int n, m, a[N], b[N], fa[N], fb[N], fc[N];

void calcmul() {
	for (int i = 0; i < N; i++) fc[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; i + j < N; j++)
			fc[i + j] += fa[i] * fb[j];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
		memset(fa, 0, sizeof(fa));
		fa[0] = 1;
		for (int i = 1; i <= n; i++) {
			memset(fb, 0, sizeof(fb));
			fb[0] = 1;
			for (int j = a[i]; j <= b[i]; j++) fb[j] = 1;
			calcmul();
			memcpy(fa, fc, sizeof(fa));
		}
		cout << fa[m] << endl;
	}
	return 0;
}

