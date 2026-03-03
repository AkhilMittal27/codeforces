#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long ans = 0;
        long long power = 1;   // represents n^0 initially

        while (k > 0) {
            if (k & 1) {
                ans = (ans + power) % MOD;
            }
            power = (power * n) % MOD;
            k >>= 1;
        }

        cout << ans << "\n";

    
    }

    return 0;
}