#include <iostream>
#include <math.h>

double sq(double x) {
	return x * x;
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(sq(x1 - x2) + sq(y1 - y2));
}

int f(double x1, double y1, double r1, double x2, double y2, double r2) {
	double l = dist(x1, y1, x2, y2);
	if (x1 == x2 && y1 == y2 && r1 == r2)
		return -1;
	if (abs(l - (r1 + r2)) < 1e-6 || abs(l - abs(r1 - r2)) < 1e-6)
		return 1;
	if (l > r1 + r2 || l < abs(r1 - r2))
		return 0;
	return 2;
}

int main() {
	double x1, y1, r1, x2, y2, r2;
	std::cin
		>> x1 >> y1 >> r1
		>> x2 >> y2 >> r2;

	std::cout << f(x1, y1, r1, x2, y2, r2);
}