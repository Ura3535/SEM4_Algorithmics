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

double vec_prod(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    Point O, A, B, C;
    std::cin >> A >> B >> C >> O;
    double
        AB_AO = vec_prod(B - A, O - A),
        BC_BO = vec_prod(C - B, O - B),
        CA_CO = vec_prod(A - C, O - C);

    if (AB_AO < 0 && BC_BO < 0 && CA_CO < 0 || AB_AO > 0 && BC_BO > 0 && CA_CO > 0)
        std::cout << "In";
    else if (AB_AO <= 0 && BC_BO <= 0 && CA_CO <= 0 || AB_AO >= 0 && BC_BO >= 0 && CA_CO >= 0)
        std::cout << "On";
    else
        std::cout << "Out";

    return 0;
}