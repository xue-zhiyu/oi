#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int quick_power(int base, int power, int mod) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * 1ll * base % mod;
		base = base * 1ll * base % mod;
		power >>= 1;
	}
	return res % mod;
}

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}

int getinv(int a, int p) {
	int x, y;
	exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x;
}

int bsgs(int a, int b, int p) {
	if (b == 1) return 0;
	int len = ceil(sqrt(p));
	unordered_map<int, int> mp;
	for (int j = 0, cura = 1; j < len; j++, cura = cura * 1ll * a % p) {
		if (mp.count(b * 1ll * cura % p)) mp[b * 1ll * cura % p] = max(mp[b * 1ll * cura % p], j);
		else mp.insert(make_pair(b * 1ll * cura % p, j));
	}
	int a_len = quick_power(a, len, p);
	for (int i = 1, cura = a_len; i <= len; i++, cura = cura * 1ll * a_len % p)
		if (mp.count(cura))
			return i * len - mp[cura];
	return -1;
}

int exbsgs(int a, int b, int p) {
	a %= p, b %= p;
	int yb = b;
	if (b == 1 || p == 1) return 0;
	int d, k, tmp = 1;
	for (k = 1; (d = gcd(a, p)) > 1; k++) {
		if (b % d) return -1;
		b /= d, p /= d;
		tmp = tmp * 1ll * (a / d) % p;
		if (tmp == b) return k;
	}
	k--;
	b = b * 1ll * getinv(tmp, p) % p;
	int res = bsgs(a, b, p);
	if (res != -1) res += k;
	for (int i = 1, cura = a; i <= k; i++, cura = cura * 1ll * a % p)
		if (cura == yb && (res == -1 || i < res))
			res = i;
	return res;
}

int main() {
	int a, b, p;
	while ((scanf("%d%d%d", &a, &p, &b), a)) {
		int ans = exbsgs(a, b, p);
		if (ans == -1) puts("No Solution");
		else printf("%d\n", ans);
	}
	return 0;
}

