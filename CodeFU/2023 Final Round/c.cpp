#include <bits/stdc++.h>

#include <string>
#include <vector>
#define ll long long
using namespace std;

const int mod=1000000007;
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

class Penalties
{
  public:
    int play(int rounds)
    {
        vector<vector<vector<mi>>> dp(rounds + 10, vector<vector<mi>>(8, vector<mi>(8, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= rounds; i++) {
            for (int s1 = 0; s1 < 8; s1++) {
                for (int s2 = 0; s2 < 8; s2++) {
                    for (int r1 : { 0, 4 }) {
                        for (int r2 : { 0, 4 }) {
                            int m1 = (s1>>1)^r1;
                            int m2 = (s2>>1)^r2;
                            if (m1 == 7 || m2 == 7) continue;
                            dp[i][s1][s2] += dp[i-1][m1][m2];
                        }
                    }
                }
            }
        }
        mi ans = 0;
        for (int r = 0; r < 2; r++) {
            for (int j = 0; j < 7; j++) {
                if (r == 0) ans += dp[rounds][7][j];
                else ans += dp[rounds][j][7];
            }
        }
        return ans.v;
    }
};

int main() {
    Penalties p;
    cout << p.play(8) << endl;
    return 0;
}