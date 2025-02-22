#include <iostream>

using namespace std;

int n, ans, anszl = -1;

int getzl(int k, int d, int a) {
	if (k - d >= 10) return k * (k - d) + a;
	else if (k >= d) return (k - d + 1) * 3 + a;
	else return a * 2;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, d, a;
		scanf("%d/%d/%d", &k, &d, &a);
		if (getzl(k, d, a) > anszl) anszl = getzl(k, d, a), ans = i;
	}
	cout << ans << endl;
	return 0;
}

