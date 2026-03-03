#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int k;
    cin >> n >> k;

    int min_terms = __builtin_popcountll(n);

    if (k < min_terms || k > n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    priority_queue<long long> pq;

    // Push initial powers from binary representation
    for (int i = 0; i < 31; i++) {
        if (n & (1LL << i)) {
            pq.push(1LL << i);
        }
    }

    // Split until we have exactly k terms
    while ((int)pq.size() < k) {
        long long top = pq.top();
        pq.pop();

        pq.push(top / 2);
        pq.push(top / 2);
    }

    // Output result
       vector<int>res;

    while (!pq.empty()) {

        res.push_back(pq.top());
        pq.pop();
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[res.size() - 1 - i] << " ";
    }
    cout << "\n";

    return 0;
}