#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 998244353;
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

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<mi> ans(N + 1);
    vector<mi> powers(N + 1);
    powers[0] = 1;
    for (int i = 1; i <= N; i++) powers[i] = powers[i-1] * 2;
    
    mi full = 0;
    for (int d1 = 1; d1 < N; d1++) {
        if (N % d1 == 0) {
            string S2 = S;
            for (int i = d1; i < N; i++) {
                if (S[i] == '.') S2[i%d1] = '.';
            }
            int cnt = 0;
            for (int i = 0; i < d1; i++) if (S2[i] == '#') cnt++;
            ans[d1] = powers[cnt];
            for (int d2 = 1; d2 < d1; d2++) {
                if (d1 % d2 == 0) ans[d1] -= ans[d2];
            }
            full += ans[d1];
        }
    }
    cout << full << endl;
    return 0;
}