#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            x++;
        } else {
            y++;
        }
    }
    ans = (ll)x * y;
    int last = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            ans = max(ans, (ll)last * last);
            last = 1;
        } else {
            last++;
        }
    }
    cout << max(ans, (ll)last * last) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}