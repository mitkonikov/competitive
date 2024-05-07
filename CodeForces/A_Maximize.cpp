#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int X;
    cin >> X;
    int ans = 0;
    int best = 0;
    for (int y = 1; y < X; y++) {
        if (gcd(X, y) + y > best) {
            best = gcd(X, y) + y;
            ans = y;
        }
    }
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