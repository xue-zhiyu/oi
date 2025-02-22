#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T --> 0) {
		int a, b, c, d, ans = 0;
		cin >> a >> b >> c >> d;
		while (a < c || b < d) {
			if (c && c < d && b != d) {
				if (d % c == b % c) ans += (d - b) / c, d = b;
				else ans += d / c, d %= c;
			} else if (d && d <= c && a != c) {
				if (c % d == a % d) ans += (c - a) / d, c = a;
				else ans += c / d, c %= d;
			} else {
				break;
			}
		}
		if (a == c && b == d) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}

