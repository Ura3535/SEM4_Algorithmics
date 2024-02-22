#include <iostream>

int main()
{
	int n;
	int arr[2000];
	std::cin >> n;
	for (int i = 0; i != 2 * n; ++i)
		std::cin >> arr[i];

	int count = 0;

	for (int i = 0; i != 2 * n - 1; ++i) {
		if (arr[i] == -1) continue;
		for (int j = i + 1; j != 2 * n; ++j)
			if (arr[j] != -1)
				if (arr[i] == arr[j]) {
					arr[j] = -1;
					break;
				}
				else
					++count;
	}
	std::cout << count;

	return 0;
}