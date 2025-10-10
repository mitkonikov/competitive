#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=1e9+7;
struct mi {
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=((ll)(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        // T(X) = M * (M - 1) ^ (X - 1)
        // 1 group of K + 1 elements  -> M    -> C(N - (K + 1) + 1, 1)
        // 2 groups of K + 2 elements -> M^2  -> C(N - (K + 2) + 1, 2) * T(N - K)
        // 3 groups of K + 3 elements -> M^3
        vector<mi> fact(2 * n + 1);
        fact[0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = fact[i-1] * i;
        }
        mi ans = 0;
        auto C = [&](int N, int K) {
            if (K > N) return mi(0);
            return fact[N] / (fact[K] * fact[N-K]);
        };
        return (mi(m) * pow(mi(m-1), n-(k+1)) * C(n-1, k)).v;
    }
};