#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

vector<int> g[N];
int tin[N], sub[N];
vector<int> order;
int timer = 0;

void dfs(int u) {
    tin[u] = timer++;
    order.push_back(u);

    sub[u] = 1;

    for (int v : g[u]) {
        dfs(v);
        sub[u] += sub[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    dfs(1);

    while (q--) {
        int u, k;
        cin >> u >> k;

        int pos = tin[u] + k - 1;

        if (pos >= tin[u] + sub[u])
            cout << -1 << "\n";
        else
            cout << order[pos] << "\n";
    }
}