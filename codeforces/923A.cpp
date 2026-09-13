// codeforces 923A
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes = {};

int getLargestFactorLargerThan(int n, int atMinimum) {
    for (auto it = primes.rbegin(); it != primes.rend() && *it > atMinimum; ++it) {
        if (n % *it == 0) return *it;
    }
    return n;
}

int getLargestFactor(int n) {
    // expandPrimes()
    vector<bool> is_prime(n + 1, true);

    int limit = sqrt(n);
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    for (auto it = primes.rbegin(); it != primes.rend(); ++it) {
        if (n % *it == 0) return *it;
    }
    return 1;
}

pair<int, int> explorePrevious(int Xi) {
    int lf = getLargestFactor(Xi);
    return {Xi - lf + 1, Xi};
}

int main()
{
    int X2, X0min;
    cin >> X2;
    auto [X1min, X1max] = explorePrevious(X2);
    X0min = X1min;
    for (const auto &p: primes) {
        int X1may = (X1min + p - 1) / p * p;
        if (X1may == p) continue;
        if (X1may <= X1max) {
           X0min = min(X0min, X1may - p + 1);
        }
    }
    cout << X0min;
    return 0;
}