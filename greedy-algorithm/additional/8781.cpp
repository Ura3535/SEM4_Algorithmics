#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	int arr[100000];
	std::vector<int> costs;
	int n = 0, B = 0;
	std::cin >> n >> B;
	for (int i = 0; i != n; ++i)
		std::cin >> arr[i];

	int count = 0;

	for (int i = 0; i != n - 1; ++i) {
		if (arr[i] & 1)
			++count;
		else
			--count;
		if (count == 0)
			costs.push_back(std::abs(arr[i] - arr[i + 1]));
	}

	std::sort(costs.begin(), costs.end(), std::less<int>());

	int res = 0;

	for (const auto& x : costs) {
		if (x <= B) {
			B -= x;
			++res;
		}
		else break;
	}

	std::cout << res;

	return 0;
}