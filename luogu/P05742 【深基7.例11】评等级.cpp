#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int id, a, b;
		cin >> id >> a >> b;
		if (a * 7 + b * 3 >= 800 && a + b > 140) cout << "Excellent" << endl;
		else cout << "Not excellent" << endl;
	}
	return 0;
}

