// Task: https://mendo.mk/Task.do?id=139

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s;
    cin >> s;
    
    string t = s;
    sort(t.begin(), t.end());
    sort(s.rbegin(), s.rend());

    // s - t
    string ans = s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] >= t[i]) {
            ans[i] = s[i] - t[i] + '0';
        } else {
            s[i-1]--;
            ans[i] = s[i] - t[i] + 10 + '0';
        }
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}