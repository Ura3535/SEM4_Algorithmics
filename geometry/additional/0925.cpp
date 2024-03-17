#include <iostream>
#include <iomanip>
#include <math.h>

double S(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


int main() {
	std::cout << std::fixed << std::setprecision(4);

	double x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double
		a = dist(x1, y1, x2, y2),
		b = dist(x1, y1, x3, y3),
		c = dist(x2, y2, x3, y3);
	std::cout << a + b + c << ' ' << S(a, b, c);
}