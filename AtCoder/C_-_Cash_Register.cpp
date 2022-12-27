#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i + 1 < n && s[i+1] == '0') {
                ans++;
                i++;
                continue;
            }
        }
        ans++;
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}