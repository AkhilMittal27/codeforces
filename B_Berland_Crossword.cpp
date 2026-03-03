#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;

        bool possible = false;

        // Try all 16 combinations of 4 corners
        for (int mask = 0; mask < 16; mask++) {

            int u = U, r = R, d = D, l = L;

            // Corners:
            // bit 0 -> top-left
            // bit 1 -> top-right
            // bit 2 -> bottom-right
            // bit 3 -> bottom-left

            if (mask & (1 << 0)) { u--; l--; } // top-left
            if (mask & (1 << 1)) { u--; r--; } // top-right
            if (mask & (1 << 2)) { d--; r--; } // bottom-right
            if (mask & (1 << 3)) { d--; l--; } // bottom-left

            // After fixing corners, remaining must be between 0 and n-2
            if (u >= 0 && u <= n-2 &&
                r >= 0 && r <= n-2 &&
                d >= 0 && d <= n-2 &&
                l >= 0 && l <= n-2) {
                possible = true;
                break;
            }
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}