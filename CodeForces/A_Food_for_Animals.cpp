#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    x -= min(x, a);
    y -= min(y, b);
    if (x + y <= c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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