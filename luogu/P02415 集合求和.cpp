#include <iostream>
#define int long long

using namespace std;

constexpr int N = 35;
int n, s[N], ans;

signed main() {
	while (cin >> s[++n]) ans += s[n]; n--;
	cout << ans * (1 << (n - 1)) << endl;
	return 0;
}

