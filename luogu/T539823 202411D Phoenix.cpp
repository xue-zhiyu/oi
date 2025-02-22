#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = i + 1; j <= n; j++) flag = flag && a[i] > a[j];
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}

