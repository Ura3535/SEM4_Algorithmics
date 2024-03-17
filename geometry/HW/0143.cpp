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

double vec_prod(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    Point O, A, B, C;
    bool left_turn, rigth_turn;
    std::cin >> O >> A >> B >> C;

    left_turn
        = vec_prod(B - A, O - A) < 0
        || vec_prod(C - B, O - B) < 0
        || vec_prod(A - C, O - C) < 0;

    rigth_turn
        = vec_prod(B - A, O - A) > 0
        || vec_prod(C - B, O - B) > 0
        || vec_prod(A - C, O - C) > 0;

    std::cout << (left_turn && rigth_turn ? 0 : 1);

    return 0;
}