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

        for(int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if(node->child[bit] == NULL)
                node->child[bit] = new Node();

            node = node->child[bit];
            node->cnt++;
        }
    }

    void remove(int x) {
        Node* node = root;

        for(int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;

            node = node->child[bit];
            node->cnt--;
        }
    }

    int maxXor(int x) {
        Node* node = root;
        int ans = 0;

        for(int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit;

            if(node->child[want] && node->child[want]->cnt > 0) {
                ans |= (1 << i);
                node = node->child[want];
            }
            else {
                node = node->child[bit];
            }
        }

        return ans;
    }
};


int main() {


    int q;
    cin >> q;

    Trie trie;

    trie.insert(0);

    while(q--) {
        char type;
        int x;

        cin >> type >> x;

        if(type == '+')
            trie.insert(x);

        else if(type == '-')
            trie.remove(x);

        else
            cout << trie.maxXor(x) << "\n";
    }
}