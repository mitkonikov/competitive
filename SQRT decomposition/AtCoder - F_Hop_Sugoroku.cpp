#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int mod=998244353;
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

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<mi> dp(N);
    dp[0] = 1;
    const int BLOCK = 300;
    vector<vector<mi>> sq(BLOCK + 10, vector<mi>(BLOCK + 10));
    mi ans = 0;
    for (int i = 0; i < N; i++) {
        mi prev = dp[i];
        for (int period = 1; period < BLOCK; period++) {
            prev += sq[i % period][period];
        }

        ans += prev;

        if (A[i] >= BLOCK) {
            for (int x = 1; i + A[i] * x < N; x++) {
                dp[i + A[i] * x] += prev;
            }
        } else {
            // { 300 offsets, 300 periods }
            // add to one of these { i % A[i], A[i] }
            // for each next index, we need to check all 300 periods with this offset
            sq[i % A[i]][A[i]] += prev;
        }
    }
    cout << ans << endl;
    return 0;
}