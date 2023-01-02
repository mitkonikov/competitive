#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct BitwiseGauss {
    static const int LOG = 61;
    ll basis[LOG];

    BitwiseGauss() {
        clear();
    }
    
    void insertVector(ll mask, int start = 0) {
        for (int i = start; i < LOG; i++) {
            if ((mask & 1 << i) == 0) continue;
    
            if (!basis[i]) {
                basis[i] = mask;
                return;
            }
    
            mask ^= basis[i];
        }
    }

    bool can(ll x) {
        for (int i = 0; i < LOG; i++) {
            if ((x & 1 << i) == 0) continue;
            x ^= basis[i];
            if (x == 0) return true;
        }
        return false;
    }

    void clear() {
        for (int i = 0; i < LOG; i++) basis[i] = 0;
    }

    void merge(const BitwiseGauss& g) {
        for (int i = 0; i < LOG; i++) {
            if (g.basis[i] == 0) continue;
            insertVector(g.basis[i], i);
        }
    }

    BitwiseGauss operator+(const BitwiseGauss& g) const {
        BitwiseGauss result;
        memcpy(result.basis, basis, LOG);
        for (int i = 0; i < LOG; i++) {
            if (g.basis[i] == 0) continue;
            result.insertVector(g.basis[i]);
        }
        return result;
    }
};

// https://nyaannyaan.github.io/library/graph/minimum-cost-arborescence.hpp
// https://nyaannyaan.github.io/library/math/grundy-number.hpp
//  -- depends on topological sort

int main() {
    int n;
    cin >> n;

    BitwiseGauss g;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g.insertVector(x);
    }

    for (int i = 0; i < g.LOG; i++) {
        for (int j = 7; j >= 0; j--) {
            if ((1LL << j) & g.basis[i]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }

    return 0;
}