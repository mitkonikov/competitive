#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cups = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans++;
            cups = min(2, cups + 2);
        } else {
            if (cups > 0) {
                cups--;
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    cout << flush;
    return 0;
}