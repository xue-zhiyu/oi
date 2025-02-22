#include <iostream>

using namespace std;

struct query {
	int id, l, r;
};

constexpr int N = 1e5 + 10;
query querys[N];
int n, m, k, a[N], cnt[N], sum, ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] = a[i - 1] ^ a[i];
	
	return 0;
}

