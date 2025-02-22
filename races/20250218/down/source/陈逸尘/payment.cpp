#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, m, l, r, mid;
inline bool check(int v) {
	int gv = 0;
	for (int i = 1; i <= k; ++i) {
		int nv = (n - gv) / v;
		if (nv <= m) return gv + (__int128)(k - i + 1) * m >= n;
		if ((gv += nv) >= n) return 1;
	}
	return 0;
}
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> k >> m; l = 1; r = 1e12;
	while (l != r) {
		mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
}
//Ë½¤ÏÃ¨¤Ç¤¹
