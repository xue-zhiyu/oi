#include <algorithm>
#include <iostream>

using namespace std;

using pii = pair<int, int>;

constexpr int N = 5010;
int n, k;
pii a[N];

int main() {
	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			auto i = lower_bound(a + i + 2, a + j);
			cout << i->first << endl;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}

