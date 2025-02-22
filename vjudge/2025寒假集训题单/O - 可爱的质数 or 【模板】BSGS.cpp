#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

int quick_power(int base, int power, int mod) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * 1ll * base % mod;
		base = base * 1ll * base % mod;
		power >>= 1;
	}
	return res;
}

int bsgs(int a, int b, int p) {
	a %= p, b %= p;
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

int main() {
	int p, a, b;
//	cin >> p >> a >> b;
//	for (int i = 0, cura = 1; ; i++, cura = cura * 1ll * a % p) {
//		if (cura == b) {
//			cout << i << endl;
//			break;
//		}
//	}
	int ans = bsgs(a, b, p);
	if (ans == -1) cout << "no solution" << endl;
	else cout << ans << endl;
	return 0;
}

