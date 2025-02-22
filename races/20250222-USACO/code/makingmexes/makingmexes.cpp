#include <iostream>
#define endl '\n'

using namespace std;

constexpr int N = 2e5 + 10;
int n, a[N], b[N], s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]]++;
	s[0] = (b[0] == 0);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (b[i] == 0);
	cout << b[0] << endl;
	for (int i = 1; i <= n; i++) cout << max(s[i - 1], b[i]) << endl;
	return 0;
}

