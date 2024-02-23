#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
const int mod = 1e9+7;
struct mi {
    int v;
    mi() { v = 0; }
    mi(ll _v) { v = int(-mod<=_v &&_v <mod?_v:_v%mod); if (v < 0) v += mod;}
    explicit operator int() const { return v; }
    friend bool operator==(const mi& a, const mi& b) { return (a.v == b.v); }
    friend bool operator!=(const mi& a, const mi& b) { return (a.v != b.v); }
    friend bool operator<(const mi& a, const mi& b) { return (a.v < b.v); }
    mi& operator+=(const mi& m) { if ((v+=m.v)>=mod) v-=mod; return *this; }
    mi& operator-=(const mi& m) { if ((v-=m.v)<0) v+=mod; return *this; }
    mi& operator*=(const mi& m) { v=((ll)(v)*m.v)%mod; return *this; }
    mi& operator/=(const mi& m) { return (*this)*=inv(m); }
    friend mi pow(mi a, ll e) { mi r=1; for(;e;a*=a,e/=2) if(e&1)r*=a; return r; }
    friend mi inv(mi a){ return pow(a, mod-2); }
    friend mi operator+(mi a, const mi& b) { return a+=b; }
    friend mi operator-(mi a, const mi& b) { return a-=b; }
    friend mi operator*(mi a, const mi& b) { return a*=b; }
    friend mi operator/(mi a, const mi& b) { return a/=b; }
 
    friend istream& operator>>(istream &is, mi &m){ ll _v; is >> _v; m = mi(_v); return is; }
    friend ostream& operator<<(ostream &os, const mi &m){ os << m.v; return os; }
};
 
const int MAXN = 3000;
vector<mi> fact(MAXN);
 
mi comb(int N, int K) {
    assert(K <= N);
    return fact[N] / (fact[K] * fact[(N - K)]);
}
 
int main() {
    fact[0] = mi(1);
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * mi(i);
    }
 
    ll N, K;
    ll P;
 
    cin >> N >> K >> P;
 
    if (K > N || K > P) {
        cout << 0 << endl;
        return 0;
    }
 
    vector<mi> S(K + 1);
    vector<mi> ra(K + 1);
    mi sumRA = 0;
    for (int si = 1; si < K; si++) {
        S[si] = pow(mi(si), P);
        for (int j = 1; j < si; j++) {
            S[si] -= comb(si, j) * S[j];
        }
        ra[si] = comb(N, si) * S[si];
        sumRA += ra[si];
    }
 
    mi all = pow(mi(N), P);
    cout << all - sumRA << endl;
 
    return 0;
}