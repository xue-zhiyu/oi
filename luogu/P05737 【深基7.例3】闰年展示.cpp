#include <iostream>
#include <vector>

using namespace std;

int l, r;
vector<int> vec;

bool is_runnian(int x) {
	if (x % 400 == 0) return true;
	return x % 4 == 0 && x % 100;
}

int main() {
	cin >> l >> r;
	for (int i = l; i <= r; i++)
		if (is_runnian(i))
			vec.push_back(i);
	cout << vec.size() << endl;
	for (int i : vec) cout << i << ' ';
	return 0;
}

