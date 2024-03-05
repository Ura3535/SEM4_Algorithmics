#include <iostream>

int main()
{
	char f;
	int n, m, t;
	std::cin >> t;
	while (t--) {
		std::cin >> f >> n >> m;
		switch (f)
		{
		case 'R': std::cout << std::min(n, m);	break;
		case 'N': std::cout << (n * m + 1) / 2;	break;
		case 'Q': std::cout << std::min(n, m);	break;
		case 'K': std::cout << ((n + 1) / 2) * ((m + 1) / 2);	break;
		default:break;
		}
		std::cout << '\n';
	}
}