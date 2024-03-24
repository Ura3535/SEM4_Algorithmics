#include <iostream>
#include <vector>

struct Point {
    Point(int x = 0, int y = 0, Point* previous = nullptr)
        : x(x), y(y), previous(previous) {}
    Point(const Point&) = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;
    bool operator==(const Point& other) {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) {
        return !(*this == other);
    }

    int x, y;
    Point* previous;
};

enum class Cell : short
{
    NoWay, Way, Start, Finish, PassedWay, Res
};

bool bfs(Cell(*arr)[252], const Point& start) {
    std::vector<Point> queue(70000);
    queue[0] = start;
    arr[start.x][start.y] = Cell::Way;

    for (auto it = queue.begin(), end = it + 1; it != end; ++it) {
        if (arr[it->x][it->y] == Cell::Finish) {
            for (auto res = &(*it); *res != start; res = res->previous)
                arr[res->x][res->y] = Cell::Res;
            arr[start.x][start.y] = Cell::Start;
            return true;
        }
        else {
            auto f = [&](int x, int y) {
                if (arr[x][y] == Cell::Way || arr[x][y] == Cell::Finish) {
                    if (arr[x][y] == Cell::Way) arr[x][y] = Cell::PassedWay;
                    *end = { x, y, &(*it) };
                    ++end;
                }
                };
            f(it->x - 1, it->y);
            f(it->x + 1, it->y);
            f(it->x, it->y - 1);
            f(it->x, it->y + 1);
        }

    }

    return false;
}

int main() {
    int n;
    char h;
    Cell arr[252][252]{};
    Point start;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> h;
            switch (h)
            {
            case '@':
                start = { i, j };
                arr[i][j] = Cell::Start;
                break;
            case 'X':
                arr[i][j] = Cell::Finish;
                break;
            case '.':
                arr[i][j] = Cell::Way;
                break;
            case 'O':
                arr[i][j] = Cell::NoWay;
                break;
            default:
                break;
            }
        }
    }

    if (!bfs(arr, start))
        std::cout << "N\n";
    else {
        std::cout << "Y\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                switch (arr[i][j])
                {
                case Cell::NoWay:
                    std::cout << 'O';
                    break;
                case Cell::Start:
                    std::cout << '@';
                    break;
                case Cell::Res:
                    std::cout << '+';
                    break;
                default:
                    std::cout << '.';
                    break;
                }
            std::cout << '\n';
        }
    }
}