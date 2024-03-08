#include <iostream>
#include <vector>
#include <algorithm>

int f(int a, int n) {
    std::vector seq{ a };
    for (int i = 0; i != n; ++i) {
        a = a * a % 10000;
        auto it = std::find(seq.begin(), seq.end(), a);
        if (it == seq.end())
            seq.push_back(a);
        else {
            n -= it - seq.begin();
            seq.assign(it, seq.end());
            break;
        }
    }

    return seq[n % seq.size()];
}

int main()
{
    int a, n, res;
    std::cin >> a >> n;
    --n;
    std::cout << f(a, n);
}
