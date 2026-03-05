#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> left(n), right(n);

    stack<pair<int,int>> st;

    // compute left span
    for(int i = 0; i < n; i++){
        int cnt = 0;

        while(!st.empty() && st.top().first % a[i] == 0){
            cnt += st.top().second + 1;
            st.pop();
        }

        left[i] = cnt;
        st.push({a[i], cnt});
    }

    while(!st.empty()) st.pop();

    // compute right span
    for(int i = n-1; i >= 0; i--){
        int cnt = 0;

        while(!st.empty() && st.top().first % a[i] == 0){
            cnt += st.top().second + 1;
            st.pop();
        }

        right[i] = cnt;
        st.push({a[i], cnt});
    }

    int best = 0;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        int len = left[i] + right[i];

        if(len > best){
            best = len;
            ans.clear();
            ans.push_back(i - left[i] + 1);  // correct l
        }
        else if(len == best){
            ans.push_back(i - left[i] + 1);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << " " << best << "\n";
    for(int x : ans) cout << x << " ";
}