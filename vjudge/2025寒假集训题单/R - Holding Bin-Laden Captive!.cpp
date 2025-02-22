#include <iostream>

using namespace std;

const int N = 10010;
int a[3];
bool fa[N], fb[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while ((cin >> a[0] >> a[1] >> a[2], a[0] || a[1] || a[2])) {
		for (int i = 0; i < N; i++) fa[i] = fb[i] = false;
		for (int i = 0; i <= a[0]; i++)
			for (int j = 0; j <= a[1] * 2; j += 2)
				fa[i + j] = true;
		for (int i = 0; i <= a[0] + a[1] * 2; i++)
			if (fa[i])
				for (int j = 0; j <= a[2] * 5; j += 5)
					fb[i + j] = true;
		for (int i = 0; i <= a[0] + a[1] * 2 + a[2] * 5 + 1; i++) {
			if (!fb[i]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}

