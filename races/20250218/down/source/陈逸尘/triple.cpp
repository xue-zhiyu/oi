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
				// �� x\in[lx,rx],y\in[ly,ry] ʱ��
				// n/x,n/y �Ƕ�ֵ�� xy <= n
				ans += (rx - lx + 1) * (ry - ly + 1) * min(n / lx, n / ly);
				ans %= mod;
			}
		}
		*/
		/*
		�������� x<=y<=z
		ö�� y�������ᱻ������ sqrt(n) ����
		y*z �������� x*z ������
		���Ծ���֮ǰ������˼·
		��Ϊ x=y<z,x<y=z,x=y=z,x<y<z �������
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
//˽��è�Ǥ�
