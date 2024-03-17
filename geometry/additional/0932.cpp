#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
	std::cout << std::fixed << std::setprecision(2);

	double s, a;
	std::cin >> s >> a;
	std::cout << (-a + sqrt(a * a + 8 * s)) / 2;
}