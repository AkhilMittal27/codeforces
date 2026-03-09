#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue;

        for (int j = 0; j < m; j++) {
            if (b[j] == 1) continue;

            long long g = gcd(a[i], b[j]);

            if (g > 1) {
                a[i] /= g;
                b[j] /= g;
            }

            if (a[i] == 1) break;
        }
    }

    cout << n << " " << m << "\n";

    for (auto x : a) cout << x << " ";
    cout << "\n";

    for (auto x : b) cout << x << " ";
    cout << "\n";
}