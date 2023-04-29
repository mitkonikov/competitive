#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int q;
    cin >> q;
    map<ll, int> frq, frqNeg;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            frq[x]++;
            frqNeg[(ll)1e18 + 1000 - x]++;
        } else if (type == 3) {
            ll x, k;
            cin >> x >> k;
            auto it = frq.lower_bound(x);
            if (it == frq.end()) {
                cout << -1 << endl;
                continue;
            }

            while (it != frq.end() && k > it->second) {
                k -= it->second;
                it = next(it);
            }

            if (it == frq.end()) {
                cout << -1 << endl;
                continue;
            }

            cout << it->first << endl;
        } else if (type == 2) {
            ll x, k;
            cin >> x >> k;
            auto it = frqNeg.lower_bound((ll)1e18 + 1000 - x);
            if (it == frqNeg.end()) {
                cout << -1 << endl;
                continue;
            }

            while (it != frqNeg.end() && k > it->second) {
                k -= it->second;
                it = next(it);
            }

            if (it == frqNeg.end()) {
                cout << -1 << endl;
                continue;
            }

            cout << (ll)1e18 + 1000 - it->first << endl;
        }
    }

    return 0;
}