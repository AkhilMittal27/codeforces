#include<bits/stdc++.h>
using namespace std;

int main ()
{

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    stack<pair<int,int>> s;
    int current_day = 1;

    for(int i = n-1; i >= 0; i--) {

        while(!s.empty() && s.top().first < v[i] && s.top().second <= current_day) {
            ans = max(ans, (int)s.size());
            s.pop();
        }

        if(!s.empty()) {
            if(!(s.top().first >= v[i])) {
                current_day = current_day + 1;
                s.push({v[i], current_day});
            }
        }
        else {
            s.push({v[i], current_day});
        }

    }

    if(ans != 0) cout << ans - 1 << "\n";
    else cout << ans << "\n";

    return 0;
}