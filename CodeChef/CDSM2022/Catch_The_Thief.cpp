#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll x, y;
    cin >> x >> y;
    ll t;
    cin >> t;
    ll r = t / y;
    if (r % 2 == 0) {
        cout << r + 1 << " " << (t % y) + 1 << endl;
    } else {
        cout << r + 1 << " " << y - (t % y) << endl;
    }
    cout << flush;
    return 0;
}