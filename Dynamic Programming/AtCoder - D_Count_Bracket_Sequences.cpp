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
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<mi>> dp(N, vector<mi>(2 * N + 100));
    if (S[0] == ')') {
        cout << 0 << endl;
        return 0;
    }

    dp[0][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int b = 0; b <= 2 * N; b++) {
            if (S[i] == '(' && b > 0) {
                dp[i][b] = dp[i-1][b-1];
            } else if (S[i] == ')') {
                dp[i][b] = dp[i-1][b+1];
            } else if (S[i] == '?') {
                dp[i][b] = (b-1>=0 ? dp[i-1][b-1] : 0) + dp[i-1][b+1];
            }
        }
    }
    cout << dp[N-1][0] << endl;
    return 0;
}