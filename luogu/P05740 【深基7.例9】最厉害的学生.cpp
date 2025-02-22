#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 1010;

struct student {
	string name;
	int a, b, c, id;
} students[N];

int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> students[i].name >> students[i].a >> students[i].b >> students[i].c, students[i].id = i;
	sort(students + 1, students + n + 1, [](student a, student b) { return a.a + a.b + a.c == b.a + b.b + b.c ? a.id < b.id : a.a + a.b + a.c > b.a + b.b + b.c; });
	cout << students[1].name << ' ' << students[1].a << ' ' << students[1].b << ' ' << students[1].c << endl;
	return 0;
}

