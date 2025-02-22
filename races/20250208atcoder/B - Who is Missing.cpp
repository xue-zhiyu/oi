#include <iostream>

using namespace std;

constexpr int N = 1010;
bool b[N];
int n, m, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i], b[a[i]] = true;
	cout << n - m << endl;
	for (int i = 1; i <= n; i++)
		if (!b[i])
			cout << i << ' ';
	cout << endl;
	return 0;
}

