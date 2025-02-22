#include <iostream>

using namespace std;

int a[3];
string str;

int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i += 5) {
		string s = str.substr(i, 5);
		int num = 0;
		if ('0' <= s[3] && s[3] <= '9') num = s[3] - '0';
		else num = a[s[3] - 'a'];
		a[s[0] - 'a'] = num;
	}
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	return 0;
}

