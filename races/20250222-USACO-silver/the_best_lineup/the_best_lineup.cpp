#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

struct cmp1 {
	bool operator()(pii a, pii b) {
		return a.first < b.first || (a.first == b.first && a.second > b.second);
	}
};

constexpr int N = 2e5 + 10;
bool book[N];
int n, a[N], b[N], c[N], tot;
priority_queue<pii, vector<pii>, cmp1> q1;

int lowbit(int x) {
	return x & -x;
}

void update(int k, int x) {
	while (k <= n) {
		c[k] += x;
		k += lowbit(k);
	}
}

int getsum(int k) {
	int res = 0;
	while (k) {
		res += c[k];
		k -= lowbit(k);
	}
	return res;
}

int solve(int k) {
	int tmp = getsum(k - 1);
	if (!tmp) return 0;
	int res = 0, sum = 0;
	for (int i = 25; ~i; i--) {
		res += 1 << i;
		if (res >= k || sum + c[res] >= tmp) res -= 1 << i;
		else sum += c[res];
	}
	return res + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T --> 0) {
		memset(c, 0, sizeof(c));
		tot = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) book[i] = false;
		while (!q1.empty()) q1.pop();
		for (int i = 1; i <= n; i++) cin >> a[i], q1.push(make_pair(a[i], i));
		int cur = 0, lstmn = 0;
		while (!q1.empty()) {
			pii t = q1.top(); q1.pop();
			if (cur < t.second) {
				cur = t.second;
				book[t.second] = true;
				lstmn = t.second;
			}
		}
		int chid = -1, chres = 0;
		for (int i = 1; i <= n; i++) {
			if (book[i]) {
				int tmp = solve(a[i]);
				if (tmp > chres && (tmp > a[lstmn] || i == lstmn)) {
					chid = i;
					chres = tmp;
				}
			} else {
				update(a[i], 1);
			}
		}
		if (chid != -1) {
			int tmp = a[chid], i = chid;
			for (; i > 1 && !book[i - 1]; i--) a[i] = a[i - 1];
			a[i] = tmp;
		}
		while (!q1.empty()) q1.pop();
		for (int i = 1; i <= n; i++) q1.push(make_pair(a[i], i));
		cur = 0;
		while (!q1.empty()) {
			pii t = q1.top(); q1.pop();
			if (cur < t.second) {
				cur = t.second;
				b[++tot] = t.first;
			}
		}
		for (int i = 1; i <= tot; i++) cout << b[i] << " \n"[i == tot];
	}
	return 0;
}

