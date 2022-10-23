#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return;
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x < 0) {
            ll f = x / 360;
            x += (360LL * (f + 1));
        }

        x %= 360;
        x = 360 - x;
        x %= 360;
        s.insert(x);
        x += 180;
        x %= 360;
        s.insert(x);
    }

    cout << s.size() << endl;
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