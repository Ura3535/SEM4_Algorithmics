#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>

struct Point {
	double x, y;
};

double sq(double x) {
	return x * x;
}

double dist(Point a, Point b) {
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

struct Item {
	Point a, b, c;
	bool operator <(const Item& other) {
		return dist(b, c) < dist(other.b, other.c);
	}
};

int main() {
	std::cout << std::fixed << std::setprecision(0);

	Point a, b, c;
	std::cin
		>> a.x >> a.y
		>> b.x >> b.y
		>> c.x >> c.y;
	Item arr[]{ {a, b, c}, {b, a, c}, {c, a, b} };

	auto it = *std::max_element(arr, arr + 3);

	Point m((it.b.x + it.c.x) / 2, (it.b.y + it.c.y) / 2);

	std::cout
		<< m.x * 2 - it.a.x << ' '
		<< m.y * 2 - it.a.y;
}