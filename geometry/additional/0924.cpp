#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
	std::cout << std::fixed << std::setprecision(2);

	double s, r, PI = 3.14159265358979323846;
	std::cin >> s >> r;
	std::cout << sqrt((r * r * PI - s) / PI);
}