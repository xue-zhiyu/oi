#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

constexpr int N = 2e5 + 10;
int n, a[N], b[N], id[N], ans[N], cnt;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main() {
	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) { return a[i] == a[j] ? b[i] < b[j] : a[i] < a[j]; });
	for (int i = 1; i <= n; i++) {
		if (q.empty() || q.top().first >= a[id[i]]) {
			q.push({b[id[i]], ++cnt});
			ans[id[i]] = cnt;
		} else {
			int qid = q.top().second; q.pop();
			q.push({b[id[i]], qid});
			ans[id[i]] = qid;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? '\n' : ' ');
	return 0;
}

