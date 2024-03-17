#include <iostream>
#include <iomanip>
#include <math.h>

double S(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
	std::cout << std::fixed << std::setprecision(4);

	double a, b, c, d, f;
	std::cin >> a >> b >> c >> d >> f;
	std::cout << S(a, b, f) + S(d, c, f);
}