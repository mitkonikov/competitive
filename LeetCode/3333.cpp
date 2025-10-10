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
    int possibleStringCount(string word, int k) {
        const int N = word.size();
        vector<int> v{ 0 };
        int count = 1;
        for (int i = 1; i < N; i++) {
            if (word[i] == word[i-1]) {
                v.back()++;
            } else {
                if (v.back() != 0) {
                    v.push_back(0);
                }
                count++;
            }
        }
        if (v.back() == 0) v.pop_back();
        int cant_choose = max(0, k - count);
        if (cant_choose == 0) {
            mi ans = 1;
            for (int i = 0; i < v.size(); i++) {
                ans *= (v[i] + 1);
            }
            return ans.v;
        }
        // cant_choose <= 2000
        // count <= 2000  ->     vec.size() <= 2000
        // dp[i+1][cc] = sum of j from 0 to v[i] of dp[i][cc - j] * (v[i] - j)
        //                                          dp[i][cc - j] * v[i]   - dp[i][cc - j] * j
        //             = v[i] * sum(dp[i][cc-k]) - s
        //   4 3 2 1
        //     4 3 2 1
        const int V = v.size();
        vector<vector<mi>> dp(V + 10, vector<mi>(cant_choose + 10));
        auto range = [&](int i, int L, int R) {
            if (R < 0) return mi(0);
            return dp[i][R] - (L - 1 >= 0 ? dp[i][L - 1] : 0);
        };
        for (int cc = 0; cc <= cant_choose; cc++) dp[0][cc] = 1;
        v.insert(v.begin(), 0);
        for (int i = 1; i <= V; i++) {
            mi s = 0;
            for (int cc = 0; cc <= cant_choose; cc++) {
                dp[i][cc] = range(i-1, cc-v[i], cc) * v[i];
                s += range(i-1, cc-v[i], cc);
                s -= range(i-1, cc-v[i]-1, cc-v[i]-1) * v[i];
                cout << "!?" << dp[i][cc] << " " << s << endl;
                dp[i][cc] -= s;
            }
            for (int cc = 1; cc <= cant_choose; cc++) {
                cout << dp[i][cc] << " ";
                dp[i][cc] += dp[i][cc-1];
            }
            cout << endl;
        }
        return range(V, cant_choose, cant_choose).v;
    }
};

int main() {
    string S;
    int K;
    cin >> S >> K;
    Solution sol;
    cout << sol.possibleStringCount(S, K) << endl;
}

