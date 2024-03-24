#include <iostream>
#include <vector>

struct Point {
    Point(int x = 0, int y = 0, int z = 0, int res = 0)
        : x(x), y(y), z(z), res(res) {}
    Point(const Point&) = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;
    bool operator==(const Point& other) {
        return x == other.x && y == other.y && z == other.z;
    }
    bool operator!=(const Point& other) {
        return !(*this == other);
    }

    int x, y, z, res;
};

enum class Cell : short
{
    NoWay, Way, Start, Finish, PassedWay, Res
};

int bfs(Cell(*arr)[32][32], const Point& start) {
    std::vector<Point> queue(30000);
    queue[0] = start;
    arr[start.x][start.y][start.z] = Cell::Way;

    for (auto it = queue.begin(), end = it + 1; it != end; ++it) {
        if (arr[it->x][it->y][it->z] == Cell::Finish) {
            return it->res;
        }
        else {
            auto f = [&](int x, int y, int z) {
                if (arr[x][y][z] == Cell::Way || arr[x][y][z] == Cell::Finish) {
                    if (arr[x][y][z] == Cell::Way) arr[x][y][z] = Cell::PassedWay;
                    *end = { x, y, z, it->res + 1 };
                    ++end;
                }
                };
            f(it->x - 1, it->y, it->z);
            f(it->x + 1, it->y, it->z);
            f(it->x, it->y - 1, it->z);
            f(it->x, it->y + 1, it->z);
            f(it->x, it->y, it->z - 1);
            f(it->x, it->y, it->z + 1);
        }
    }

    return -1;
}

int input_and_calculate(int l, int r, int c) {
    char h;
    Cell arr[32][32][32]{};
    Point start;

    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= r; ++j) {
            for (int k = 1; k <= c; ++k) {
                std::cin >> h;
                switch (h)
                {
                case 'S':
                    start = { i, j, k, 0 };
                    arr[i][j][k] = Cell::Start;
                    break;
                case 'E':
                    arr[i][j][k] = Cell::Finish;
                    break;
                case '.':
                    arr[i][j][k] = Cell::Way;
                    break;
                case '#':
                    arr[i][j][k] = Cell::NoWay;
                    break;
                default:
                    break;
                }
            }
        }
    }

    return bfs(arr, start);
}

int main() {
    int l, r, c, res;
    while (true) {
        std::cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        res = input_and_calculate(l, r, c);
        if (res == -1)
            std::cout << "Trapped!\n";
        else
            std::cout << "Escaped in " << res << " minute(s).\n";

    }
}