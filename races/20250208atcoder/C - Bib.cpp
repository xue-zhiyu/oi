#include <iostream>

using namespace std;

constexpr int N = 3e5 + 10;
int n, a[N], b[N], c[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]] = i;
	for (int i = 1; i <= n; i++) cout << a[b[c[i]]] << (i == n ? '\n' : ' ');
	return 0;
}

