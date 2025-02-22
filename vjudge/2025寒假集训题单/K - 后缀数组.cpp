#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long

using namespace std;

constexpr int N = 3e5 + 10, B1 = 131, M1 = 1e9 + 7;
char s[N];
int n, hb1[N], hs1[N], hb2[N], hs2[N], id[N];

int gethash1(int l, int r) {
	return ((hs1[r] - hs1[l - 1] * hb1[r - l + 1] % M1) % M1 + M1) % M1;
}

bool equals(int l1, int r1, int l2, int r2) {
	return r1 - l1 == r2 - l2 && (r1 - l1 < 0 || (gethash1(l1, r1) == gethash1(l2, r2)));
}

int findPerfixLength(int l1, int r1, int l2, int r2) {
	int l = 0, r = min(r1 - l1 + 1, r2 - l2 + 1);
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (equals(l1, l1 + mid - 1, l2, l2 + mid - 1)) l = mid;
		else r = mid - 1;
	}
	return l;
}

int compare(int l1, int r1, int l2, int r2) {
	int l = findPerfixLength(l1, r1, l2, r2);
	if (l == r1 - l1 + 1) {
		if (l == r2 - l2 + 1) {
			return 0;
		} else {
			return -1;
		}
	} else {
		if (l == r2 - l2 + 1) {
			return 1;
		} else {
			if (s[l1 + l] < s[l2 + l]) return -1;
			else if (s[l1 + l] > s[l2 + l]) return 1;
			else return 0;
		}
	}
}

signed main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	hb1[0] = hb2[0] = 1;
	for (int i = 1; i <= n; i++) {
		hb1[i] = hb1[i - 1] * B1 % M1;
		hs1[i] = (hs1[i - 1] * B1 % M1 + s[i] - 'a') % M1;
		id[i] = i;
	}
	sort(id + 1, id + n + 1, [&](int i, int j) { return compare(i, n, j, n) == -1; });
	for (int i = 1; i <= n; i++) cout << id[i] - 1 << (i == n ? '\n' : ' ');
	cout << "0 ";
	for (int i = 2; i <= n; i++) cout << findPerfixLength(id[i - 1], n, id[i], n) << (i == n ? '\n' : ' ');
	return 0;
}

