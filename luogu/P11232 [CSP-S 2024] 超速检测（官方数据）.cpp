#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define endl '\n'

using namespace std;

constexpr int N = 1e5 + 10, N3 = 3e5 + 10, M = 1e6 + 10, K = 25;
bool canbe[N], isok[30];
int n, m, L, V, p[N], l[N], r[N], cnt[M], ans1, ans2, stmx[M], clog2[M], carid[N];

bool ishasp(int l, int r) {
	if (l > r) return false;
	if (l) return cnt[r] - cnt[l - 1];
	return cnt[r];
}

void solve() {
	ans1 = ans2 = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(stmx, 0, sizeof(stmx));
	memset(canbe, false, sizeof(canbe));
	cin >> n >> m >> L >> V;
	for (int i = 1; i <= n; i++) {
		int d, v, a;
		cin >> d >> v >> a;
		if (a == 0) {
			if (v > V) l[i] = d, r[i] = L;
			else l[i] = r[i] = -1;
		} else if (a > 0) {
			double endspeed = sqrt(v * 1. * v + 2 * a * L);
			if (endspeed > V) {
				l[i] = max((V * V - v * v) / (2 * a) + 1 + d, d);
				r[i] = L;
			}
			else l[i] = r[i] = -1;
		} else {
			if (v > V) {
				l[i] = d;
				r[i] = min((V * V - v * v) / (2 * a) - ((V * V - v * v) % (2 * a) == 0) + d, L);
			} else l[i] = r[i] = -1;
		}
		carid[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		cnt[p[i]]++;
	}
	for (int i = 1; i <= L; i++) cnt[i] += cnt[i - 1];
	for (int i = 1; i <= n; i++)
		if (l[i] != -1)
			if (ishasp(l[i], r[i]))
				ans1++, canbe[i] = true;
	cout << ans1 << ' ';
	int cur = -1;
	sort(carid + 1, carid + n + 1, [&](int i, int j) {return r[i] == r[j] ? l[i] < l[j] : r[i] < r[j]; });
	for (int i = 1; i <= n; i++) {
		stmx[p[i]] = p[i];
	}
	for (int i = 1; i <= L; i++) stmx[i] = max(stmx[i - 1], stmx[i]);
	for (int i = 1; i <= n; i++)
		if (canbe[carid[i]])
			if (cur < l[carid[i]])
				ans2++, cur = stmx[r[carid[i]]];
	cout << m - ans2 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	clog2[1] = 0;
	for (int i = 2; i < M; i++) clog2[i] = clog2[i >> 1] + 1;
	int T;
	cin >> T;
	while (T --> 0) solve();
	return 0;
}

