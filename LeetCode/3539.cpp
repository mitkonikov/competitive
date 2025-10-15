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
    int magicalSum(int M, int K, vector<int>& nums) {
        // [1, 1, 1] -> 10 * 10 * 10 -> 1000
        // [1, 2, 2] -> 10 * 10 * 10 -> 1000    other permutations: [2, 1, 2], [2, 2, 1]
        // [2, 2, 2] -> 10 * 10 * 10 -> 1000
        // prod(seq) + prod(seq2)
        // (common)(prod(seq \ common) + prod(seq2 \ common))
        // from dp[i][carry][bits][m]
        //    - index i am at
        //    - carry of the binary representation
        //    - bits already set
        //    - size already 
        // 10, 20, 5, 30 ... -> n! / (prod_i of a[i]!)
        const int N = nums.size();
        const int C = 15;
        vector<vector<vector<vector<bool>>>> R(N + 1, vector<vector<vector<bool>>>(C, vector<vector<bool>>(K + 1, vector<bool>(M + 1))));
        vector<vector<vector<vector<mi>>>> dp(N + 1, vector<vector<vector<mi>>>(C, vector<vector<mi>>(K + 1, vector<mi>(M + 1, 0))));
        vector<mi> fact(M + 1);
        fact[0] = 1;
        for (int i = 1; i < M + 1; i++) fact[i] = fact[i-1] * i;
        R[0][0][0][0] = true;
        dp[0][0][0][0] = 1;
        for (int i = 0; i < N; i++) {
            mi inc = 1;
            for (int take = 0; take <= M; take++) {
                for (int carry = 0; carry < C; carry++) {
                    for (int bits = 0; bits <= K; bits++) {
                        for (int size = 0; size <= M; size++) {
                            if (!R[i][carry][bits][size]) continue;
                            // given take, find the new carry, bits and size properly
                            int new_carry = carry + take;
                            int bit_on = new_carry & 1;
                            int new_bits = bits + bit_on;
                            new_carry >>= 1;
                            int new_size = size + take;
                            if (new_carry < C && new_bits <= K && new_size <= M) {
                                R[i + 1][new_carry][new_bits][new_size] = true;
                                dp[i + 1][new_carry][new_bits][new_size] += (dp[i][carry][bits][size] * inc) / fact[take];
                            }
                        }
                    }
                }
                inc *= nums[i];
            }
        }
        mi ans = 0;
        for (int c = 0; c < C; c++) {
            int bit_count = __builtin_popcount(c);
            if (K-bit_count>=0) ans += dp[N][c][K-bit_count][M];
        }
        return (ans * fact[M]).v;
    }
};