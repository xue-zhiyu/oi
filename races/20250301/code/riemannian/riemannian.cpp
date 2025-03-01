#include <cmath>
#include <iostream>

using namespace std;

using ll = long long;

double power(double base, int power) {
	double res = 1.;
	while (power) {
		if (power & 1) res = res * base;
		base = base * base;
		power >>= 1;
	}
	return res;
}

int main() {
	int T, ans1 = 0, ans2 = 0;
	cin >> T;
	while (T --> 0) {
		ll n;
		cin >> n;
		ans1 ^= int((sqrt(3) + 3) / 6 * power(1 + sqrt(3), n) + (3 - sqrt(3)) / 6 * power(1 - sqrt(3), n) - 0.5);
		ans2 ^= int((sqrt(3) * 2 + 3) / 6 * power(1 + sqrt(3), n) + (3 - sqrt(3) * 2) / 6 * power(1 - sqrt(3), n) - 0.5);
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}

