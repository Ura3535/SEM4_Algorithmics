#include <iostream>
#include <math.h>
#include <algorithm>

int sng(double x) {
    return (0 < x) - (x < 0);
}

int f(double a, double b, double c) {
    if (a + b <= c) return 2;
    return sng(a * a + b * b - c * c);
}

int main() {
    double sides[3];
    std::cin >> sides[0] >> sides[1] >> sides[2];
    std::sort(sides, sides + 3);

    switch (f(sides[0], sides[1], sides[2]))
    {
    case -1: std::cout << "OBTUSE";     break;
    case 0: std::cout << "RIGHT";      break;
    case 1: std::cout << "ACUTE";      break;
    case 2: std::cout << "IMPOSSIBLE"; break;
    default: break;
    }

    return 0;
}