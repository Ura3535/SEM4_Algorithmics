#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>

void compute_favorite_numbers(std::vector<int>& favorite_numbers) {
    std::bitset<500001> sieve;
    sieve.reset();
    for (long long i = 2; i <= 500000; i++) {
        if (!sieve[i]) {
            if (std::to_string(i).find("13") == std::string::npos)
                favorite_numbers.push_back(i);

            for (long long j = i * i; j <= 500000; j += i) {
                sieve[j] = true;
            }
        }
    }
}

int main()
{
    std::vector<int> favorite_numbers;
    compute_favorite_numbers(favorite_numbers);
    int a, b;
    std::cin >> a >> b;

    auto it_a = std::find_if(favorite_numbers.begin(), favorite_numbers.end(), [a](int arg) {return arg >= a; });
    auto it_b = std::find_if(favorite_numbers.begin(), favorite_numbers.end(), [b](int arg) {return arg > b; }) - 1;


    std::cout << it_b - it_a + 1;
}