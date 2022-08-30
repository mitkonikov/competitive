#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

void testCase() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d == b * c) {
        cout << 0 << endl;
    } else {
        if (a % gcd(b, d) != 0 && c % gcd(b, d) != 0) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
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