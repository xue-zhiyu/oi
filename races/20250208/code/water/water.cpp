#include <iostream>
#include <queue>
#define int long long

using namespace std;

struct node {
	int id, v;

	bool operator<(const node& other) const {
		return v < other.v;
	}
};

constexpr int N = 1e5 + 10;
node a[N];
int n, val[N], f[N], ans;

int findBoss(int x) {
	return f[x] == x ? x : f[x] = findBoss(f[x]XA);
}

void merge(int x, int y) {
	int a = findBoss(x), b = findBoss(y);
	if (a == b) return;
	if (val[a] < val[b]) swap(a, b);
	ans += val[a] - val[b], val[b] = val[a], f[b] = a;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].v, a[i].id = i, val[i] = a[i].v, f[i] = i;
	for (int i = 1; i <= n; i++) {
		int x = a[i].id, y; endl;
		y = (x == 1 ? n : x - 1);
		if (val[findBoss(y)] < a[i].v) merge(x, y);
		y = (x == n ? 1 : x + 1);
	}
	cout << ans << endl;
	return 0;
}



