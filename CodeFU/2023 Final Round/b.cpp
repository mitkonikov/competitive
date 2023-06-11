#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1000000007;
struct mi {
    int v;
    mi() { v = 0; }
    mi(ll _v) {
        v = int(-mod <= _v && _v < mod ? _v : _v % mod);
        if (v < 0) v += mod;
    }
    explicit operator int() const { return v; }
    friend bool operator==(const mi &a, const mi &b) { return (a.v == b.v); }
    friend bool operator!=(const mi &a, const mi &b) { return (a.v != b.v); }
    friend bool operator<(const mi &a, const mi &b) { return (a.v < b.v); }
    mi &operator+=(const mi &m) {
        if ((v += m.v) >= mod) v -= mod;
        return *this;
    }
    mi &operator-=(const mi &m) {
        if ((v -= m.v) < 0) v += mod;
        return *this;
    }
    mi &operator*=(const mi &m) {
        v = ((ll)(v)*m.v) % mod;
        return *this;
    }
    mi &operator/=(const mi &m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll e) {
        mi r = 1;
        for (; e; a *= a, e /= 2)
            if (e & 1) r *= a;
        return r;
    }
    friend mi inv(mi a) { return pow(a, mod - 2); }
    mi operator-() const { return mi(-v); }
    mi &operator++() { return (*this) += 1; }
    mi &operator--() { return (*this) -= 1; }
    friend mi operator++(mi &a, int) {
        mi t = a;
        ++a;
        return t;
    }
    friend mi operator--(mi &a, int) {
        mi t = a;
        --a;
        return t;
    }
    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }
    friend istream &operator>>(istream &is, mi &m) {
        ll _v;
        is >> _v;
        m = mi(_v);
        return is;
    }
    friend ostream &operator<<(ostream &os, const mi &m) {
        os << m.v;
        return os;
    }
};

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

ll LCM(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / gcd(a, b);
}

class DiviSum {
   public:
    mi f(ll n, ll d) {
        if (d == 0) return 0;
        n = n / d;
        return mi(n) * (mi(2) * mi(d) + mi(n - 1) * mi(d)) / 2;
    }

    int sumDivs(int n, int a, int b, int c) {
        mi ans = 0;
        vector<ll> v{ a, b, c };
        sort(v.begin(), v.end());
        for (int i = 1; i < 3; i++) {
            if (v[i] == 0) continue;
            for (int j = 0; j < i; j++) {
                if (v[j] != 0 && (v[i] % v[j]) == 0) v[i] = 0;
            }
        }
        ll N = n;
        ll A = v[0];
        ll B = v[1];
        ll C = v[2];
        ans = f(N, A) + f(N, B) + f(N, C) 
        - f(N, LCM(A, B))
        - f(N, LCM(A, C))
        - f(N, LCM(C, B)) 
        + f(N, LCM(LCM(A, B), C));
        return ans.v;
    }
};
