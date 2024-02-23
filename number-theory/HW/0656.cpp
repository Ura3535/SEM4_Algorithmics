#include <iostream>

int main()
{
    long long n;
    bool q = false;
    std::cin >> n;

    while (true) {
        if (n <= 1) break;
        n = (n - 1) / 9 + 1;
        q = true;
        if (n <= 1) break;
        n = (n - 1) / 2 + 1;
        q = false;
    }
    std::cout << (q ? "Stan wins." : "Ollie wins.");
}