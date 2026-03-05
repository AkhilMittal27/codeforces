#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n, m, x;
        cin >> n >> m >> x;

        vector<int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        for (int i = 1; i <= m; i++) {
            pq.push({0, i});
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            auto [height, id] = pq.top();
            pq.pop();

            ans[i] = id;
            height += h[i];

            pq.push({height, id});
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}