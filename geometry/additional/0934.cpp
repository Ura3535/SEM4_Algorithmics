#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
	std::cout << std::fixed << std::setprecision(2);

	double a, b, c;
	std::cin >> a >> b >> c;
	double p = (a + b + c) / 2,
		s = sqrt(p * (p - a) * (p - b) * (p - c));
	std::cout << 2 * s / a << ' ' << 2 * s / b << ' ' << 2 * s / c;
}