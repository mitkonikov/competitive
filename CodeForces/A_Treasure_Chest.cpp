#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int X, Y, K;
    cin >> X >> Y >> K;
    if (X <= 0 && Y <= 0) {
        X *= -1;
        Y *= -1;
    }

    if (X * Y < 0) {
        cout << abs(X) + abs(Y) << endl;
        return;
    }

    if (X >= 0 && Y >= 0 && Y > X) {
        int mvX = min(X + K, Y);
        cout << Y + (Y - mvX) << endl;
    } else {
        cout << max(X, Y) << endl;
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