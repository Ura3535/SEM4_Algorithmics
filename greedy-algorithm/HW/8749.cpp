#include <iostream>
#include <string>
#include <algorithm>

int shifting(char a, char b) {
	int res = b - a;
	if (res < 0)
		res += 'Z' - 'A' + 1;

	return res;
}

int find(const std::string& s, char x, int begin) {
	int val = 100;
	int res = 0;

	for (int i = begin; i != s.size(); ++i) {
		if (shifting(x, s[i]) < val) {
			val = shifting(x, s[i]);
			res = i;
		}
	}

	return res;
}

int main()
{
	std::string A, B;
	std::cin >> A >> B;

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	int res = 0;
	for (int i = 0; i != A.size(); ++i) {
		int j = find(B, A[i], i);

		std::swap(B[i], B[j]);

		res += shifting(A[i], B[i]);
	}

	std::cout << res;

	return 0;
}