#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef unsigned long long ull;
const int MAXN = 1e7 + 5;

int a[MAXN];
ull pre_sum[MAXN], pre_xor[MAXN], pre_h1[MAXN], pre_h2[MAXN];
unordered_map<int, pair<ull, ull>> hash_map;

// ??64????
ull rand64() {
    static mt19937_64 gen(random_device{}());
    return gen();
}

signed main() {
	freopen("galaseek.in", "r", stdin);
	freopen("galaseek.out", "w", stdout);
    int n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    // ???????
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (!hash_map.count(x)) {
            hash_map[x] = {rand64(), rand64()};
        }
    }

    // ???????
    pre_sum[0] = 0;
    pre_xor[0] = 0;
    pre_h1[0] = 0;
    pre_h2[0] = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        auto &h = hash_map[x];
        pre_sum[i+1] = pre_sum[i] + x;
        pre_xor[i+1] = pre_xor[i] ^ x;
        pre_h1[i+1] = pre_h1[i] + h.first;
        pre_h2[i+1] = pre_h2[i] + h.second;
    }

    // ??????
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if (len1 != len2) {
            puts("No");
            continue;
        }

        // ??????
        ull sum1 = pre_sum[r1] - pre_sum[l1-1];
        ull sum2 = pre_sum[r2] - pre_sum[l2-1];
        if (sum1 != sum2) {
            puts("No");
            continue;
        }

        ull xor1 = pre_xor[r1] ^ pre_xor[l1-1];
        ull xor2 = pre_xor[r2] ^ pre_xor[l2-1];
        if (xor1 != xor2) {
            puts("No");
            continue;
        }

        ull h1_sum1 = pre_h1[r1] - pre_h1[l1-1];
        ull h1_sum2 = pre_h1[r2] - pre_h1[l2-1];
        if (h1_sum1 != h1_sum2) {
            puts("No");
            continue;
        }

        ull h2_sum1 = pre_h2[r1] - pre_h2[l1-1];
        ull h2_sum2 = pre_h2[r2] - pre_h2[l2-1];
        if (h2_sum1 != h2_sum2) {
            puts("No");
            continue;
        }

        puts("Yes");
    }

    return 0;
}

