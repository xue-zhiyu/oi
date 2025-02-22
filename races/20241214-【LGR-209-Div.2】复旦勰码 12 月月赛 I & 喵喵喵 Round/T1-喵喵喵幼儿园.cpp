#include <iostream>
#define endl '\n'

using namespace std;

int q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q --> 0) {
		string a, b, c;
		cin >> a >> b >> c;
		c = c.substr(0, c.size() - 1);
		if (a != "eat") {
			cout << a << endl;
		} else if (c != "eat") {
			cout << c << endl;
		} else {
			cout << b << endl;
		}
	}
	return 0;
}

