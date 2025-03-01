#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#define double long double

using namespace std;

constexpr int N = 1e5 + 10;
constexpr double eps = 1e-9;
int n, id[N];
double l[N], r[N], p[N], ans[N];
mt19937 rd(time(nullptr));

double get(double l, double r) {
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (rd() & 1) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i], id[i] = i;
	for (int i = 1; i <= 10000000; i++) {
		for (int j = 1; j <= n; j++) p[j] = get(l[j], r[j]);
		sort(id + 1, id + i + 1, [&](int i, int j) { return p[i] > p[j]; });
		for (int j = 1; j <= n; j++) ans[j] += id[j];
		for (int j = 1; j <= n; j++) cout << i << ": " << fixed << setprecision(6) << ans[j] / i << ' ';
	}
	for (int i = 1; i <= n; i++) cout << fixed << setprecision(6) << ans[i] / 10000000 << endl;
	return 0;
}

