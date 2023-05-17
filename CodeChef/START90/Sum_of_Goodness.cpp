#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

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

vector<mi> fact;

inline mi comb(int N, int K) {
    if (K > N) return 0;
    return fact[N] * inv(fact[K] * fact[N-K]);
}

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> frq(N + 10);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        frq[A[i]]++;
    }
    mi ans = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        ans += comb(i, A[i] - 1) * pow(mi(2), N - i - 1);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact.resize(2e5 + 100, 1);
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = fact[i-1] * i;
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}