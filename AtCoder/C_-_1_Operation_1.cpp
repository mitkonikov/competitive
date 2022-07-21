#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    
    if (d < 0) {
        ll R = a + d * (n-1);
        a = R;
        d *= -1;
    }

    ll L = a;
    ll R = a+d*(n-1);
    if (L <= x && x <= R) {
        ll m;
        if (d != 0) m = (x - L) % d;
        else m = 0;
        cout << min(m, d - m) << endl;
        return 0;
    }

    cout << ((x < L) ? L - x : x - R) << endl;
    return 0;
}