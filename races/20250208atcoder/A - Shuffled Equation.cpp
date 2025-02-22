#include <iostream>

using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c;
	if (a * b == c || a * c == b || b * c == a) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

