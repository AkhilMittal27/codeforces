#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[2];
    int cnt;

    Node() {
        child[0] = child[1] = NULL;
        cnt = 0;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node* node = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (!node->child[bit])
                node->child[bit] = new Node();

            node = node->child[bit];
            node->cnt++;
        }
    }

    long long countLess(int x, int k) {
        Node* node = root;
        long long ans = 0;

        for (int i = 30; i >= 0; i--) {
            if (!node) break;

            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                if (node->child[xb])
                    ans += node->child[xb]->cnt;

                node = node->child[1 - xb];
            }
            else {
                node = node->child[xb];
            }
        }

        return ans;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    Trie trie;

    trie.insert(0);

    long long ans = 0;
    int px = 0;

    for (int i = 0; i < n; i++) {

        px ^= a[i];

        long long less = trie.countLess(px, k);

        ans += (i + 1) - less;

        trie.insert(px);
    }

    cout << ans;
}