#include <iostream>

using namespace std;

int t, a, b, c, d;

int main() {
	cin >> t >> a >> b >> c >> d;
	if (t) cout << max(a - c, 0) + max(b - d, 0);
	else cout << a + b << endl;
	return 0;
}

