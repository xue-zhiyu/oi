#include <iostream>

using namespace std;

constexpr int N = 1e6 + 10;
int n, q, a[N], s[N];

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) s[i] = s[i + 1] + a[i];
	while (q --> 0) {
		int k;
		cin >> k;
		int l = 1, r = n;
		if (s[1] < k) {
			cout << -1 << endl;
			return 0;
		}
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (s[mid] > k) r = mid - 1;
			else l = mid;
		}
		cout << l - 1 << endl;
	}
	return 0;
}

