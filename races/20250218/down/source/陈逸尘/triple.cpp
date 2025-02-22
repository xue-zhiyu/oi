#include<bits/stdc++.h>
using namespace std;
#define int long long
int t, n, ans;
constexpr int mod = 998244353;
signed main() {
	ios::sync_with_stdio(0);
	for (cin >> t; t; t--) {
		cin >> n; ans = 0;
		/*
		for (int lx = 1, rx = 0; lx <= n; lx = rx + 1) {
			rx = (n / (n / lx));
			ans += min(rx, n / lx) * (n / lx) * (rx - lx + 1);
			ans %= mod;
			for (int ly = rx + 1, ry = 0; ly <= n; ly = ry + 1) {
				ry = (n / (n / ly)); ry = min(ry, n / lx);
				if (ry < ly) break;
				// 在 x\in[lx,rx],y\in[ly,ry] 时，
				// n/x,n/y 是定值且 xy <= n
				ans += (rx - lx + 1) * (ry - ly + 1) * min(n / lx, n / ly);
				ans %= mod;
			}
		}
		*/
		/*
		尝试限制 x<=y<=z
		枚举 y，这样会被限制在 sqrt(n) 级别
		y*z 不超，则 x*z 不超！
		所以就是之前的神奇思路
		分为 x=y<z,x<y=z,x=y=z,x<y<z 四种情况
		*/
		for (int y = 1; y * y <= n; ++y) {
			ans += (n / y - y) * 3; // x=y<z
			ans += (y - 1) * 3; // x<y=z
			ans++; //x=y=z
			ans += (n / y - y) * (y - 1) * 6;// x<y<z
			ans %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}
//私は猫です
