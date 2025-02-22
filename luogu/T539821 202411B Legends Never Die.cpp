#include <iostream>

using namespace std;

int a, b, c, k;

void print(bool flag) {
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	cin >> a >> b >> c >> k;
	print(a + b >= k);
	print(a + c >= k);
	print(b + c >= k);
	return 0;
}

