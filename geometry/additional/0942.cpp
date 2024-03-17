#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
    std::cout << std::fixed << std::setprecision(3);

    double a, a1, b, b1, s, s1, d, d1;
    std::cin >> a >> a1 >> s >> s1 >> b >> b1 >> d >> d1;

    std::cout << (a + b) / 2 << ' ' << (b1 + a1) / 2 << '\n';
    std::cout << sqrt((a - b) * (a - b) + (a1 - b1) * (a1 - b1)) << ' '
        << sqrt((s - d) * (s - d) + (s1 - d1) * (s1 - d1)) << '\n';

}