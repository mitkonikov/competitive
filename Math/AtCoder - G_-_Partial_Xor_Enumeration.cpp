#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct BitwiseGauss {
    // maybe ll or bitset?
    ll LOG = 61;
    vector<ll> basis;

    BitwiseGauss() {
        basis.resize(LOG, 0);
    }
    
    void insertVector(ll mask) {
        for (ll i = LOG - 1; i >= 0; i--) {
            if ((mask & 1LL << i) == 0) continue;
    
            if (!basis[i]) {
                basis[i] = mask;
                return;
            }
    
            mask ^= basis[i];
        }
    }

    vector<ll> getX() {
        set<ll> result;
        for (ll i = 0; i < LOG; i++) {
            if (basis[i]) result.insert(i);
        }
        for (int i = LOG - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if ((basis[i] ^ basis[j]) < basis[i]) {
                    basis[i] ^= basis[j];
                }
            }
        }
        vector<ll> res;
        for (auto el: result) res.push_back(el);
        return res;
    }
};

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    BitwiseGauss gauss;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        gauss.insertVector(x);
    }
    auto X = gauss.getX();
    for (ll i = l - 1; i <= r - 1; i++) {
        ll ans = 0;
        for (ll j = 0; j < 61; j++) {
            if ((i & (1LL << j))) {
                ans ^= gauss.basis[X[j]];
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}