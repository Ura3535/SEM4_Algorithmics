#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>

void compute_prime_numbers(std::vector<long long>& prime_numbers, std::vector<long long>& special_prime_numbers) {
    std::bitset<1000001> sieve;
    sieve.reset();
    special_prime_numbers.push_back(2);
    for (long long i = 2; i <= 1000000; i++) {
        if (!sieve[i]) {
            prime_numbers.push_back(i);
            if (i % 4 == 1)
                special_prime_numbers.push_back(i);

            for (long long j = i * i; j <= 1000000; j += i) {
                sieve[j] = true;
            }
        }
    }
}

int main()
{
    std::vector<long long> prime_numbers, special_prime_numbers;
    compute_prime_numbers(prime_numbers, special_prime_numbers);
    long long a, b;

    while (std::cin >> a >> b)
    {
        if (a == -1 && b == -1) break;

        auto it_a = std::find_if(prime_numbers.begin(), prime_numbers.end(), [a](long long arg) {return arg >= a; });
        auto it_b = std::find_if(prime_numbers.begin(), prime_numbers.end(), [b](long long arg) {return arg > b; });

        auto it_c = std::find_if(special_prime_numbers.begin(), special_prime_numbers.end(), [a](long long arg) {return arg >= a; });
        auto it_d = std::find_if(special_prime_numbers.begin(), special_prime_numbers.end(), [b](long long arg) {return arg > b; });

        std::cout << a << ' ' << b << ' ' << it_b - it_a << ' ' << it_d - it_c << '\n';
    }
}