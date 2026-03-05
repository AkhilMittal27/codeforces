#include <bits/stdc++.h>
using namespace std;

int main() {
    

    string s;
    cin >> s;

    stack<int> st;
    st.push(-1);  // base index

    int max_len = 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            }
            else {
                int len = i - st.top();

                if (len > max_len) {
                    max_len = len;
                    count = 1;
                }
                else if (len == max_len) {
                    count++;
                }
            }
        }
    }

    if (max_len == 0) {
        cout << "0 1\n";
    }
    else {
        cout << max_len << " " << count << "\n";
    }

    return 0;
}