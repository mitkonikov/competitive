#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p1 = 0, p2 = 0, p3 = 0;
    ll ans = 0;
    while (p1 < n && p2 < n && p3 < n) {
        while (p2+1 < n && a[p2 + 1] >= a[p2]) { // check if p2 + 1 < n
            p2++;
            p3++;
        }
        
        if (p2 == p1) {
            p1++;
            p2++;
            p3++;
        } else {
            while (p3+1 < n && a[p3+1] <= a[p3]) {
                p3++;
            }

            ans = max(ans, min(a[p2] - a[p1], a[p2] - a[p3]));
            p1 = p3;
            p2 = p3;
        }
    }

    cout << ans << endl;
    cout << flush;
    return 0;
}