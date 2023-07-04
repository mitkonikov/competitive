#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int bal = 0;
    stack<char> st;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            st.push(S[i]);
            bal++;
        } else if (S[i] == ')') {
            if (bal > 0) {
                while (st.top() != '(') {
                    st.pop();
                }
                st.pop();
                bal--;
            } else {
                st.push(S[i]);
                bal = 0;
            }
        } else {
            st.push(S[i]);
        }
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}