#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 1010;

struct stu {
	string name;
	int a, b, c;

	stu() {
	}

	stu(const stu& other) {
		name = other.name;
		a = other.a, b = other.b, c = other.c;
	}
} a[N];

struct pstu {
	stu a, b;

	pstu(stu _a, stu _b) : a(_a), b(_b) {
		if (a.name > b.name) swap(a, b);
	}

	bool operator<(const pstu other) const {
		return a.name == other.a.name ? b.name < other.b.name : a.name < other.a.name;
	}
};

int n;
vector<pstu> vec;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].name >> a[i].a >> a[i].b >> a[i].c;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (abs(a[i].a - a[j].a) <= 5 && abs(a[i].b - a[j].b) <= 5 && abs(a[i].c - a[j].c) <= 5 && abs(a[i].a + a[i].b + a[i].c - a[j].a - a[j].b - a[j].c) <= 10)
				vec.push_back(pstu(a[i], a[j]));
	sort(vec.begin(), vec.end());
	for (pstu& i : vec) cout << i.a.name << ' ' << i.b.name << endl;
	return 0;
}

