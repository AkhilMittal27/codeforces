#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> st;

    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;

        int p = x % 2;

        if(!st.empty() && st.back() == p){
            st.pop_back();   
        }
        else{
            st.push_back(p);
        }
    }

    int ones = 0, zeros = 0;

    for(int x : st){
        if(x == 1) ones++;
        else zeros++;
    }

    if(ones > 0 && zeros > 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}