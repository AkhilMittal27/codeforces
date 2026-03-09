#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000000;

int pf[MAXN + 1];
long long prefix[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAXN; i++) {
        if (pf[i] == 0) { // prime
            for (int j = i; j <= MAXN; j += i) {
                int x = j;
                while (x % i == 0) {
                    pf[j]++;
                    x /= i;
                }
            }
        }
    }

    for (int i = 1; i <= MAXN; i++)
        prefix[i] = prefix[i - 1] + pf[i];

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[a] - prefix[b] << "\n";
    }
}