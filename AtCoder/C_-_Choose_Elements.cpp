#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll A = a[0];
    ll B = b[0];
    bool possible = true;
    for (int i = 1; i < n; i++) {
        if (A == (ll)INT_MAX * 10000 && B == (ll)INT_MAX * 10000) {
            possible = false;
            break;
        }

        ll prevA = A;
        if (abs(A - a[i]) <= k || abs(B - a[i]) <= k) {
            A = a[i];
        } else {
            A = (ll)INT_MAX  * 10000;
        }

        if (abs(prevA - b[i]) <= k || abs(B - b[i]) <= k) {
            B = b[i];
        } else {
            B = (ll)INT_MAX  * 10000;
        }
    }

    if (A == (ll)INT_MAX  * 10000 && B == (ll)INT_MAX  * 10000) {
        possible = false;
    }

    cout << (possible ? "Yes" : "No") << endl;
    return 0;
}