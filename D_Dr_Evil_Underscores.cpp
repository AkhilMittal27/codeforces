#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[10];
    int cnt;
    int last;

    Node() {
        memset(child, 0, sizeof(child));
        cnt = 0;
        last = -1;
    }
};

Node* root = new Node();

void insert(const string &s, int id) {

    Node* node = root;

    for(char c : s) {

        int d = c - '0';

        if(!node->child[d])
            node->child[d] = new Node();

        node = node->child[d];

        if(node->last != id) {
            node->cnt++;
            node->last = id;
        }
    }
}

int getCount(const string &s) {

    Node* node = root;

    for(char c : s)
        node = node->child[c-'0'];

    return node->cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> nums(n);

    for(int i=0;i<n;i++)
        cin >> nums[i];

    // build trie
    for(int i=0;i<n;i++){

        for(int l=0;l<9;l++){

            string cur="";

            for(int r=l;r<9;r++){
                cur+=nums[i][r];
                insert(cur,i);
            }
        }
    }

    // find answers
    for(int i=0;i<n;i++){

        string ans="";

        for(int len=1;len<=9;len++){

            bool ok=false;

            for(int start=0;start+len<=9;start++){

                string sub=nums[i].substr(start,len);

                if(getCount(sub)==1){
                    ans=sub;
                    ok=true;
                    break;
                }
            }

            if(ok) break;
        }

        cout<<ans<<"\n";
    }
}