#include <iostream>
#include <queue>
#include <vector>

class cmp {
public:
    bool operator() (double a, double b) {
        return a > b;
    }
};

int main()
{

    std::priority_queue<double, std::vector<double>, cmp> arr;
    int n;
    double p;
    std::cin >> n >> p;
    for (int i = 0; i != n; ++i) {
        double tmp;
        std::cin >> tmp;
        arr.push(tmp);
    }

    while (true) {
        double a = arr.top();
        arr.pop();
        if (arr.empty()) {
            std::cout << a;
            return 0;
        }
        double b = arr.top();
        arr.pop();
        arr.push((a + b) * (1 - (p / 100)));
    }
}