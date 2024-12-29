#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll L, R, G;
    cin >> L >> R >> G;
    if (G > R) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    ll A = ((L + G - 1) / G) * G;
    ll B = (R / G) * G;
    if (G >= L && G <= R) {
        cout << A << " " << B << endl;
        return;
    }
    for (int i = 0; i < (R - L) / G; i++) {
        for (int j = 0; j <= i; j++) {
            if (gcd(A + G * j, B - (i - j) * G) == G) {
                cout << A + G * j << " " << B - (i - j) * G << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
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