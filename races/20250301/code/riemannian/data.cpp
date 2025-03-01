#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream f("riemannian.in");
	int T = 1e5;
	f << T << endl;
	while (T --> 0) {
		f << "1000000000000" << endl;
	}
	return 0;
}

