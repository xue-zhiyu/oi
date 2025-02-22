#include <iostream>

using namespace std;

int x, a, b, l, r, lastx, n, X;

int main() {
	cin >> n >> X;
	for(int i = 1; i <= n; i++) {
		cin >> x >> a >> b;
		if (r + (x - lastx) >= b) r = (r - (x - lastx) - b) & 1 ? b - 1 : b - 2;
		else r += (x - lastx);
		if (l - (x - lastx) <= a) l = (a - l + (x - lastx)) & 1 ? a + 1 : a + 2;
		else l -= (x - lastx);
		if (r < l) {
			cout << "NIE" << endl;
			return 0;
		}
		else lastx = x;
	}
	cout << (lastx + l) / 2 << endl;
	return 0;
}

