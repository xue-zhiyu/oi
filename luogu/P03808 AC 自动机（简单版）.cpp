#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int N = 1e6 + 10;
char strdat[2 * N], *strMode[N], strMain[N];
int n, fail[N], ch[N][26], idx;
int val[N];

void push(char str[]) {
	int cur = 0;
	for (int i = 0; str[i]; i++) {
		if (!ch[cur][str[i] - 'a']) ch[cur][str[i] - 'a'] = ++idx;
		cur = ch[cur][str[i] - 'a'];
	}
	val[cur]++;
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; i++)
		if (ch[0][i])
			q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
}

int query(char str[]) {
	int res = 0, cur = 0;
	for (int i = 0; str[i]; i++) {
		cur = ch[cur][str[i] - 'a'];
		for (int j = cur; j && val[j] != -1; j = fail[j])
			res += val[j], val[j] = -1;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, cl = 0; i <= n; cl += strlen(strMode[i++]) + 1) scanf("%s", (strMode[i] = strdat + cl + 1));
	scanf("%s", strMain);
	for (int i = 1; i <= n; i++) push(strMode[i]);
	build();
	cout << query(strMain) << endl;
	return 0;
}

