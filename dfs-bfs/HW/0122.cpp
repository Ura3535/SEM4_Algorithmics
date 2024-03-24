#include <iostream>
#include <vector>

int f(std::vector<std::vector<int>>& transitions, bool* arr, int a, int b, int d) {
    if (a == b) return 1;
    if (d == 0) return 0;

    int res = 0;
    arr[a] = true;
    for (int x : transitions[a])
        if (!arr[x])
            res += f(transitions, arr, x, b, d - 1);
    arr[a] = false;

    return res;
}

int main() {
    int n, k, a, b, d, u, v;
    bool arr[51]{};
    std::cin >> n >> k >> a >> b >> d;
    std::vector<std::vector<int>> transitions(n + 1);
    while (k--) {
        std::cin >> u >> v;
        transitions[u].push_back(v);
    }

    std::cout << f(transitions, arr, a, b, d);

    return 0;
}