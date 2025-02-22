#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << fixed << setprecision(2) << (sqrt(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) * 1.)
									   + sqrt(((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) * 1.)
									   + sqrt(((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)) * 1.)) << endl;
	return 0;
}

