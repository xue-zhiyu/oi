#include <algorithm>
#include <iostream>

using namespace std;

using psi = pair<string, int>;

constexpr int N = 1e6 + 10;
psi a[N];
string s;
int n, k;

int main() {
	freopen("silent.in", "r", stdin);
	freopen("silent.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T --> 0) {
		cin >> n >> k >> s;
		for (int i = 1; i <= n - k + 1; i++) a[i].first = s.substr(0, i - 1) + s.substr(i + k - 1), a[i].second = i;
		sort(a + 1, a + n - k + 2);
		long long ans = 0;
		for (int i = 1; i <= n - k + 1; i++) ans = (ans + i * 1ll * a[i].second) % 1000000007ll;
		cout << ans << endl;
	}
	return 0;
}

