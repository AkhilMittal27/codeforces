#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

vector<int> tree[N];
bool matched[N];
int ans = 0;

void dfs(int node, int parent) {

    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs(child, node);
    }

    for (int child : tree[node]) {
        if (child == parent) continue;

        if (!matched[node] && !matched[child]) {
            matched[node] = matched[child] = true;
            ans++;
        }
    }
}

int main() {


    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans;
}