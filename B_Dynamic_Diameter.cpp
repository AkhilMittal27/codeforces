#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
vector<int> g[N];

vector<int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    // first BFS
    auto d0 = bfs(1, n);

    int A = 1;
    for (int i = 1; i <= n; i++)
        if (d0[i] > d0[A])
            A = i;

    // second BFS
    auto distA = bfs(A, n);

    int B = A;
    for (int i = 1; i <= n; i++)
        if (distA[i] > distA[B])
            B = i;

    // third BFS
    auto distB = bfs(B, n);

    int D = distA[B];

    for (int i = 1; i <= n; i++) {
        int ans = max(D, max(distA[i], distB[i]) + 1);
        cout << ans << "\n";
    }
}