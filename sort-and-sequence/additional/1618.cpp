#include <iostream>
#include <algorithm>

int main()
{
    int arrn[1001]{};
    int arrm[1001]{};
    int arrlast[1001]{};
    int arrres[1001]{};
    int n, m;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> arrn[i];
    std::cin >> m;
    for (int i = 0; i != m; ++i) {
        std::cin >> arrm[i];
        if (std::find(arrn, arrn + n, arrm[i]) == arrn + n)
            arrlast[i] = n;
        else
            for (int j = i; j >= 0; --j) {
                auto it = std::find(arrn + arrlast[j], arrn + n, arrm[i]);
                if (it != arrn + n && (arrres[j] + 1 > arrres[i] || arrres[j] + 1 == arrres[i] && it - arrn + 1 < arrlast[i])) {
                    arrres[i] = arrres[j] + 1;
                    arrlast[i] = it - arrn + 1;
                }
            }
    }
    std::cout << *std::max_element(arrres, arrres + m);
}