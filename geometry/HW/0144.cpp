#include <iostream>

struct Point {

    Point operator + (const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    Point operator - (const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << p.x << ' ' << p.y;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }

    double x;
    double y;
};

using Vector = Point;

double scalar_prod(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    Point A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int count
        = (scalar_prod(B - A, C - B) == 0 ? 1 : 0)
        + (scalar_prod(C - B, D - C) == 0 ? 1 : 0)
        + (scalar_prod(D - C, A - D) == 0 ? 1 : 0)
        + (scalar_prod(A - D, B - A) == 0 ? 1 : 0);

    std::cout << count;

    return 0;
}