#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    long long n;
    cin >> n;

    if (isPrime(n))
        cout << 1;
    else if (n % 2 == 0)
        cout << 2;
    else if (isPrime(n - 2))
        cout << 2;
    else
        cout << 3;
}