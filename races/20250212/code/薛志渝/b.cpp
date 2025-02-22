#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

constexpr int N = 1e6 + 10;
int s[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, C;
	cin >> T >> C;
	for (int i = 1; i < N; i++) s[i] = s[i - 1] + (gcd((C * i) ^ C, C) == 1);
	while (T --> 0) {
		int l, r;
		cin >> l >> r;
		if (r > N) cout << 0 << endl;
		else cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}

