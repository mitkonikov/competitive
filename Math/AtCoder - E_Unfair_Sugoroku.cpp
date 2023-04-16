#include <bits/stdc++.h>
#define ll long long

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

mi dp[101][101];
mi new_dp[101][101];

void reset(int N) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            new_dp[i][j] = 0;
        }
    }
}

int main() {
    int N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;

    reset(N);
    swap(dp, new_dp);
    reset(N);

    dp[A][B] = 1;
    mi ans = 0;
    for (int turns = 0; turns < 2 * N + 5; turns++) {
        for (int i = 0; i <= N; i++) reset(N);

        if (turns % 2 == 0) { // T
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dp[i][j] == 0) continue;
                    for (int p = 1; p <= P; p++) {
                        int res_i = min(i + p, N);
                        int res_j = j;
                        new_dp[res_i][res_j] += dp[i][j] / P;
                    }
                }
            }

            mi sum = 0;
            for (int j = 0; j <= N; j++) {
                sum += new_dp[N][j];
                new_dp[N][j] = 0;
            }

            ans += sum;
        } else { // A
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dp[i][j] == 0) continue;
                    for (int p = 1; p <= Q; p++) {
                        int res_i = i;
                        int res_j = min(j + p, N);
                        new_dp[res_i][res_j] += dp[i][j] / Q;
                    }
                }
            }

            mi sum = 0;
            for (int j = 0; j <= N; j++) {
                sum += new_dp[j][N];
                new_dp[j][N] = 0;
            }
        }
        swap(dp, new_dp);
    }
    cout << ans << endl;
    return 0;
}