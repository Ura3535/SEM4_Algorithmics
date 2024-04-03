#include <iostream>
#include <string>
#include <queue>

struct Point {
    Point(int x, int y, int val)
        : x(x), y(y), val(val) {}
    Point() = default;
    Point(const Point&) = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;
    bool operator==(const Point& other) {
        return x == other.x && y == other.y;
    }

    int x, y;
    int val;
};

int bfs(const Point& s, const Point& f) {
    bool flag[9][9]{};
    Point curr;
    std::queue<Point> queue;
    queue.push(s);

    while (!queue.empty()) {
        curr = queue.front();
        if (curr == f)
            return curr.val;
        queue.pop();

        auto f = [&](int x, int y, int val) {
            if (0 < x && x < 9 && 0 < y && y < 9 && !flag[x][y]) {
                flag[x][y] = true;
                queue.push({ x, y, val });
            }
            };

        f(curr.x - 2, curr.y + 1, curr.val + 1);
        f(curr.x - 2, curr.y - 1, curr.val + 1);
        f(curr.x - 1, curr.y + 2, curr.val + 1);
        f(curr.x - 1, curr.y - 2, curr.val + 1);
        f(curr.x + 2, curr.y + 1, curr.val + 1);
        f(curr.x + 2, curr.y - 1, curr.val + 1);
        f(curr.x + 1, curr.y + 2, curr.val + 1);
        f(curr.x + 1, curr.y - 2, curr.val + 1);
    }

    return -1;
}


int main() {
    std::string a, b;
    Point s, f;

    while (std::cin >> a >> b) {
        s = { a[0] - 'a' + 1, a[1] - '0', 0 };
        f = { b[0] - 'a' + 1, b[1] - '0', 0 };

        std::cout << "To get from " << a << " to " << b << " takes " << bfs(s, f) << " knight moves.\n";
    }
    return 0;
}