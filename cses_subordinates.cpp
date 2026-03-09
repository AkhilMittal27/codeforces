#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

vector<int> tree[N];
int sub[N];

void dfs(int node) {
    sub[node] = 1;

    for (int child : tree[node]) {
        dfs(child);
        sub[node] += sub[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] - 1 << " ";
    }
}