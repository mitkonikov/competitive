#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < b) {
        cout << -1 << endl;
        return;
    }
    if (((a + (d - b)) < c)) {
        cout << -1 << endl;
        return;
    }
    cout << (d - b) + (((a + (d - b)) - c)) << endl;
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