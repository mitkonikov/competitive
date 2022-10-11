#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

struct Binomial {
    int mxn = -1;
    vector<int> inv, fact;
 
    // inverse = pow(a, mod - 2);
    int inverse(int a) {
        int m = MOD;
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return (u + MOD) % MOD;
    }
    
    void preprocess() {
        fact[0] = 1;
        for (int i = 1; i < mxn; i++) {
            fact[i] = (ll)fact[i-1] * i % MOD;
        }
    }
 
    Binomial(int mxn = (int)2e5 + 10) {
        this->mxn = mxn;
        fact.resize(mxn);
        preprocess();
    }

    int C(int n, int k) {
        if (k > n) swap(k, n);
        return ((ll)fact[n] * inverse((ll)fact[k] * fact[n-k] % MOD)) % MOD;
    }
};

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    n += 2;

    vector<pair<int, int>> points(n);
    for (int i = 1; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        points[i] = { x, y };
    }

    points[0] = { 0, 0 };
    points[n-1] = { w - 1, h - 1 };

    sort(points.begin(), points.end());

    Binomial b(2e5 + 10);
    vector<ll> f(n), g(n);
    g[0] = 0;

    for (int i = 1; i < n; i++) {
        int x1, y1;
        tie(x1, y1) = points[i];

        for (int j = i-1; j >= 0; j--) {
            int x2, y2;
            tie(x2, y2) = points[j];

            if (y2 > y1) continue;
            
            ll X = x1 - x2;
            ll Y = y1 - y2;

            f[i] = (f[i] + (g[j] * b.C(X + Y, Y)) % MOD) % MOD;
        }

        g[i] = (b.C(x1 + y1, y1) - f[i] + MOD) % MOD;
    }

    cout << g[n-1] << endl;
    return 0;
}