#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll S, E;
    cin >> S >> E;
    if (E > S) {
        cout << "NO" << endl;
        return;
    }
    vector<ll> got{S};
    while (S % 2 == 0) {
        S /= 2;
        got.push_back(S);
    }
    if (got.back() == 1) {
        cout << "YES" << endl;
        return;
    }
    // k0 * got[0] + k1 * got[1] + ... = E
    cout << (E % got.back() == 0 ? "YES" : "NO") << endl;
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