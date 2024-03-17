#include <iostream>
#include <iomanip>
#include <math.h>

struct Point {
	double x, y, z;
};

double sq(double x) {
	return x * x;
}

double dist(Point a, Point b) {
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z));
}

int main() {
	std::cout << std::fixed << std::setprecision(3);

	double x1, y1, x2, y2, z2;
	std::cin
		>> x1 >> y1
		>> x2 >> y2 >> z2;

	Point a{ x1, y1, 0 }, b{ x2, y2, z2 };

	std::cout << 1 / dist(a, b);
}