#include <iomanip>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int C = 27, sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += (gcd(((C * i) ^ C), C) == 1);
		cout << sum << endl;
	}
	return 0;
}

