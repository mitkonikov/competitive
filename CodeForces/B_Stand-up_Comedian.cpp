#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0) {
        if (a + b + c + d > 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }
    int ans = a;
    int al = a;
    int bob = a;
    int mn = min(b, c);
    ans += 2 * mn;
    b -= mn;
    c -= mn;
    if (b > c) {
        int take = min(b, a + 1);
        ans += take;
        bob -= take;
        al += take;
    } else {
        int take = min(c, a + 1);
        ans += take;
        al -= take;
        bob += take;
    }

    if (al < 0 || b < 0) {
        cout << ans << endl;
        return;
    }
    
    int take = min({ bob + 1, al + 1, d });
    ans += take;
    cout << ans << endl;
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