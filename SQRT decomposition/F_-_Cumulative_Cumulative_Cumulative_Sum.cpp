#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

// a[0], a[1]+x,        a[2],                 a[3]
// a[0], a[0]+a[1],   a[0]+a[1]+a[2],       a[0]+a[1]+a[2]+a[3]
// a[0], 2*a[0]+a[1], 3*a[0]+2*a[1]+a[2],   4*a[0]+3*a[1]+2*a[2]+a[3]

// query: 3
// change: 1
// diff = 2
// 2 * 3 / 2 => 3
// 3 * 4 / 2 => 6

// query: 2
// change: 1
// diff = 1
// diff2 = 2
// 2 * 3 / 2 = 3

// a[0], 3*a[0]+a[1], 6*a[0]+3*a[1]+a[2],   10*a[0]+6*a[1]+3*a[2]+a[3]

// a[0],    2*a[0]+a[1], 3*a[0]+2*a[1]+a[2], 4*a[0]+3*a[1]+2*a[2]+a[3]
// a[0],    a[0]+a[1],  a[0]+a[1]+a[2]
// a[0],    a[1],      a[2]

//     ___a[0]+a[1]___     ___ ___

// 1, 0, 3
// 1, 3, 6
// 1, 4, 10
// 1, 5, 15

// 1, 0, 3
// 1, 1, 4
// 1, 2, 6
// 1, 3, 9

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> init(n);
    vector<int> a(init);
    for (int i = 0; i < n; i++) cin >> init[i];
    const int MOD = 998244353;
    auto rebuild = [&]() {
        copy(init.begin(), init.end(), a.begin());
        for (int rep = 0; rep < 3; rep++) {
            vector<int> new_pref(n);
            ll pref = 0;
            for (int i = 0; i < n; i++) {
                pref = (pref + a[i]) % MOD;
                new_pref[i] = pref;
            }
            a.swap(new_pref);
        }
    };
    rebuild();
    map<int, int> changes;
    int sq = 400;
    for (int qq = 0; qq < q; qq++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, v;
            cin >> x >> v;
            x--;
            changes[x] = v;
        } else if (type == 2) {
            int where;
            cin >> where;
            where--;
            ll ans = a[where];
            for (auto &p: changes) {
                if (p.first <= where) { // it affects it
                    ll diff = p.second - init[p.first];
                    ll index_diff = where - p.first + 1;
                    ll acc = index_diff * (index_diff + 1) / 2;
                    ans = (ans + ((diff % MOD) * (acc % MOD)) % MOD) % MOD;
                }
            }
            cout << (ans + MOD) % MOD << endl;
        }
        if ((qq + 1) % 400 == 0) {
            for (auto &p: changes) {
                init[p.first] = p.second;
            }
            rebuild();
            changes.clear();
        }
    }
    cout << flush;
    return 0;
}