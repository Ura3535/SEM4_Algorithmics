#include <iostream>
#include <vector>

int main()
{
	std::vector<int> arr{ 500, 200, 100, 50, 20, 10 };
	int n = 0, k = 0;
	std::cin >> n;
	for (const auto& x : arr) {
		k += n / x;
		n -= (n / x) * x;
	}
	if (n != 0)
		std::cout << -1;
	else
		std::cout << k;
}