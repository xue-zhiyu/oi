#include <cmath>
#include <iostream>
#define int long long

using namespace std;

struct node {
	int pos, l, r;
};

constexpr int N = 5e5 + 10, inf = 0x7f7f7f7f7f7f7f7fll;
int n, tar;
node nodes[N];

int getdis(int x1, int y1, int x2, int y2) {
	if ((x2 - x1 + abs(y2 - y1)) & 1) return inf;
	return x2 - x1 - 
}

signed main() {
	freopen("Flappy.in", "r", stdin);
	freopen("Flappy.out", "w", stdout);
	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n >> tar;
	for (int i = 1; i <= n; i++) cin >> nodes[i].pos >> nodes[i].l >> nodes[i].r, nodes[i].l++, nodes[i].r--;
	
	return 0;
}

