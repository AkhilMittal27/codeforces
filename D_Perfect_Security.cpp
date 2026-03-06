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

        for(int i = 29; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if(node->child[bit] == NULL)
                node->child[bit] = new Node();

            node = node->child[bit];
            node->cnt++;
        }
    }

    void remove(int x) {
        Node* node = root;

        for(int i = 29; i >= 0; i--) {
            int bit = (x >> i) & 1;
            node = node->child[bit];
            node->cnt--;
        }
    }

    int minXor(int x) {
        Node* node = root;
        int val = 0;

        for(int i = 29; i >= 0; i--) {

            int bit = (x >> i) & 1;

            if(node->child[bit] && node->child[bit]->cnt > 0) {
                node = node->child[bit];
                val |= (bit << i);
            }
            else {
                node = node->child[1-bit];
                val |= ((1-bit) << i);
            }
        }

        return val;
    }
};

int main() {


    int n;
    cin >> n;

    vector<int> A(n), P(n);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> P[i];

    Trie trie;

    for(int x : P)
        trie.insert(x);

    for(int i = 0; i < n; i++) {

        int p = trie.minXor(A[i]);

        cout << (A[i] ^ p) << " ";

        trie.remove(p);
    }

}