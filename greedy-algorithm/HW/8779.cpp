#include <iostream>
#include <vector>

int main()
{
	std::vector<int> arr{ 100, 20, 10, 5, 1 };
	long long n = 0, k = 0;
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
