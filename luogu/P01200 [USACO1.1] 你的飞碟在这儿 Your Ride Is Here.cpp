#include <iostream>

using namespace std;

string a, b;
int sa = 1, sb = 1;

int main() {
	cin >> a >> b;
	for (char i : a) sa = sa * (i - 'A' + 1) % 47;
	for (char i : b) sb = sb * (i - 'A' + 1) % 47;
	if (sa == sb) cout << "GO" << endl;
	else cout << "STAY" << endl;
	return 0;
}

