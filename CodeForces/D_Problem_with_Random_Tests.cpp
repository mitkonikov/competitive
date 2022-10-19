#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int first_one = -1;
    int first_zero = 0;
    bool one = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first_one == -1) first_one = i;
            one = true;
            continue;
        }

        if (one && s[i] == '0') {
            first_zero = i;
            break;
        }
    }

    string ans = s;
    for (int i = 0; i <= first_zero - first_one; i++) {
        string current = s;
        for (int j = 0; j + i < n; j++) {
            current[i + j] |= s[j];
        }

        ans = max(ans, current);
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;
    return 0;
}