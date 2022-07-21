#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 998244353;
struct mint {
    int value;

    mint(long long x = 0) { value = normalize(x); }

    int normalize(long long x) {
        if (x < -mod || x >= mod)
            x %= mod;
        if (x < 0)
            x += mod;
        return static_cast<int>(x);
    }

    explicit operator int() const { return value; }

    mint operator-() const { return mint(-value); }

    mint &operator+=(mint rhs) {
        if ((value += rhs.value) >= mod)
            value -= mod;
        return *this;
    }

    mint &operator-=(mint rhs) {
        if ((value -= rhs.value) < 0)
            value += mod;
        return *this;
    }

    mint &operator*=(mint rhs) {
        value = normalize(static_cast<long long>(value) * rhs.value);
        return *this;
    }

    mint &operator/=(mint rhs) { return *this *= mint(inverse(rhs.value, mod)); }

    static int inverse(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    bool operator==(mint rhs) const { return value == rhs.value; }

    bool operator!=(mint rhs) const { return !(*this == rhs); }

    friend mint operator+(mint lhs, mint rhs) { return lhs += rhs; }

    friend mint operator-(mint lhs, mint rhs) { return lhs -= rhs; }

    friend mint operator*(mint lhs, mint rhs) { return lhs *= rhs; }

    friend mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }
};

struct binomial {
    int mxn = -1;
    vector<int> inv, fact;

    binomial(int mxn = (int)2e5 + 10) {
        this->mxn = mxn;
        fact.resize(mxn);
    }

    void calc_inv() {
        inv.resize(mod);
        inv[1] = 1;
        for(int i = 2; i < mod; ++i)
            inv[i] = mod - (mod/i) * inv[mod%i] % mod;
    }
    
    void preprocess() {
        fact[0] = 1;
        for (int i = 1; i < mxn; i++) {
            fact[i] = (ll)fact[i-1] * i % mod;
        }
    }

    int bin(int n, int k) {
        return ((mint)fact[n] * mint::inverse((ll)fact[k] * fact[n-k] % mod, mod)).value;
    }
};

int main() {
    mint n;
    cin >> n.value;

    binomial b(500 * 500 + 100);
    b.preprocess();

    mint all = b.fact[(n * n).value];
    all = all - 
        (n*n) 
        * b.bin((n*n).value, 2*n.value-1)
        * b.fact[(n - 1).value] 
        * b.fact[(n - 1).value]
        * b.fact[((n-1)*(n-1)).value];

    cout << all.value << endl;
    return 0;
}