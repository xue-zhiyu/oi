#include <iostream>

using namespace std;

long long getfac(int n) {
	if (!n) return 1;
	return getfac(n - 1) * n;
}

int main() {
	int n;
	cin >> n;
	cout << getfac(n) << endl;
	return 0;
}

