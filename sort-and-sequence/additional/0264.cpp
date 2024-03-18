#include <iostream>
#include <algorithm>

int main()
{
    int arr[1001];
    int res[1001];
    int n;
    std::cin >> n;
    for (int i = 0; i != n; ++i) {
        std::cin >> arr[i];
        res[i] = 1;
        for (int j = 0; j != i; ++j)
            if (arr[j] == arr[i] || arr[j] != 0 && arr[i] % arr[j] == 0)
                res[i] = std::max(res[i], res[j] + 1);
    }
    std::cout << *std::max_element(res, res + n);
}