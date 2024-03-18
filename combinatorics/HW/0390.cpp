#include <iostream>
#include <unordered_map>
#include <string>

long long factorial(int x) {
    long long res = 1;
    while (x != 0)
        res *= x--;
    return res;
}

int main() {
    std::unordered_map<char, int> arr;
    std::string s;
    std::cin >> s;
    for (char x : s)
        ++arr[x];

    long long res = factorial(s.size());
    for (auto& x : arr)
        res /= factorial(x.second);

    std::cout << res;
}