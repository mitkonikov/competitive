#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}