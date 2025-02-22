#include <algorithm>
#include <iostream>

using namespace std;

int maxof(int a, int b, int c, int d, int e) {
	return max(a, max(b, max(c, max(d, e))));
}

int main() {
	int c, n, asdf[6] = {};
	cin >> c >> n;
	while (n --> 0) {
		int a[5];
		for (int i = 0; i < 5; i++) cin >> a[i];
		sort(a, a + 5);
		for (int i = 4; i >= 0; i--) {
			if (c >= a[i]) {
				c -= a[i];
				asdf[a[i]]++;
				break;
			}
		}
	}
	for (int i = 1; i <= 5; i++) cout << asdf[i] << (i == 5 ? '\n' : ' ');
	cout << c << endl;
	return 0;
}

