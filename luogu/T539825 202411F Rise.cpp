#include <iostream>

using namespace std;

const int N = 1010;
int n, m, h[N];

int main() {
	cin >> n >> m;
	while (m --> 0) {
		string opt;
		int l, r;
		cin >> opt >> l >> r;
		if (opt == "water") {
			for (int i = l; i <= r; i++) h[i]++;
		} else {
			int cnt = 0, k;
			cin >> k;
			for (int i = l; i <= r; i++) {
				if (h[i] >= k) {
					h[i] = 0;
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}

