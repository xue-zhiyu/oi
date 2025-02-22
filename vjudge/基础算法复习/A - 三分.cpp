#include <iostream>
#include <iomanip>

using namespace std;

constexpr int N = 20;
constexpr double eps = 1e-6;
int n;
double l, r, a[N];

double calc(double x) {
	double ans = 0., xn = 1.;
	for (int i = 0; i <= n; i++) {
		ans += a[i] * xn;
		xn *= x;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> l >> r;
	for (int i = n; i >= 0; i--) cin >> a[i];
	while (r - l > eps) {
		double lmid = l + (r - l) / 3;
		double rmid = r - (r - l) / 3;
		if (calc(lmid) < calc(rmid)) l = lmid;
		else r = rmid;
	}
	cout << fixed << setprecision(5) << l << endl;
	return 0;
}

