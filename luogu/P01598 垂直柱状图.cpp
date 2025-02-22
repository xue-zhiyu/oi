#include <iostream>

using namespace std;

int cnt[26], mxn;

int main() {
	char ch;
	while (cin >> ch) if ('A' <= ch && ch <= 'Z') cnt[ch - 'A']++;
	for (int i = 0; i < 26; i++) mxn = max(mxn, cnt[i]);
	for (int i = mxn; i; i--) {
		for (int j = 0; j < 26; j++) {
			if (i <= cnt[j]) cout << '*';
			else cout << ' ';
			if (j != 25) cout << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < 26; i++) cout << char(i + 'A') << (i == 25 ? "" : " ");
	return 0;
}

