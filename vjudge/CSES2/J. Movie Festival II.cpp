#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

constexpr int N = 2e5 + 10;
multiset<int> s;
int n, k, l[N], r[N], id[N], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i], id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) { return r[i] < r[j]; });
	for (int i = 1; i <= n; i++) {
		if (s.empty()) s.insert(-r[id[i]]), ans++;
		else {
			auto it = s.lower_bound(-l[id[i]]);
			if (it == s.end()) {
				if (s.size() < k) s.insert(-r[id[i]]), ans++;
			} else {
				s.erase(it);
				s.insert(-r[id[i]]);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

