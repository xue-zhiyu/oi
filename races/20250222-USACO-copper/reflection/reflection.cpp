#include <initializer_list>
#include <iostream>
#define endl '\n'
#define LL (a[i][j])
#define LR (a[i][n - j + 1])
#define RL (a[n - i + 1][j])
#define RR (a[n - i + 1][n - j + 1])
#define gLL(__i__, __j__) (a[__i__][__j__])
#define gLR(__i__, __j__) (a[__i__][n - __j__ + 1])
#define gRL(__i__, __j__) (a[n - __i__ + 1][__j__])
#define gRR(__i__, __j__) (a[n - __i__ + 1][n - __j__ + 1])
#define getAns min(min(ans[0], ans[1]), min(ans[2], ans[3]))

using namespace std;

constexpr int N = 2010;
bool a[N][N];
int n, m, q, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	m = n >> 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch;
			cin >> ch;
			a[i][j] = (ch == '#');
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			ans += min(LL + LR + RL + RR, 4 - (LL + LR + RL + RR));
	cout << ans << endl;
	while (q --> 0) {
		int chx, chy;
		cin >> chx >> chy;
		int ysx = (chx >= m ? n - chx + 1 : chx), ysy = (chy >= m ? n - chy + 1 : chy);
		ans -= min(gLL(ysx, ysy) + gLR(ysx, ysy) + gRL(ysx, ysy) + gRR(ysx, ysy), 4 - (gLL(ysx, ysy) + gLR(ysx, ysy) + gRL(ysx, ysy) + gRR(ysx, ysy)));
		a[chx][chy] = !a[chx][chy];
		ans += min(gLL(ysx, ysy) + gLR(ysx, ysy) + gRL(ysx, ysy) + gRR(ysx, ysy), 4 - (gLL(ysx, ysy) + gLR(ysx, ysy) + gRL(ysx, ysy) + gRR(ysx, ysy)));
		cout << ans << endl;
	}
	return 0;
}

