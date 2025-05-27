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
    int colorTheGrid(int m, int n) {
        auto get_colors = [&](int t) {
            vector<int> colors(m);
            for (int j = 0; j < m; j++) {
                colors[j] = t % 3;
                t /= 3;
            }
            return colors;
        };

        const int MX = pow(3, m);
        vector<int> valid;
        for (int i = 0; i < MX; i++) {
            auto colors = get_colors(i);
            bool ok = true;
            for (int j = 0; j < m - 1; j++) {
                ok &= (colors[j] != colors[j+1]);
            }
            if (ok) valid.push_back(i);
        }

        int V = valid.size();
        vector<vector<int>> mat(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j) continue;
                auto c1 = get_colors(valid[i]);
                auto c2 = get_colors(valid[j]);
                bool ok = true;
                for (int k = 0; k < m; k++) {
                    ok &= (c1[k] != c2[k]);
                }
                if (ok) mat[i].push_back(valid[j]);
            }
        }
        
        vector<mi> dp(MX), new_dp(MX);
        for (int i = 0; i < V; i++) dp[valid[i]] = 1;

        for (int i = 1; i < n; i++) {
            fill(new_dp.begin(), new_dp.end(), 0);
            for (int c1 = 0; c1 < V; c1++) {
                for (int c2 : mat[c1]) {
                    new_dp[valid[c1]] += dp[c2];
                }
            }
            dp.swap(new_dp);
        }

        mi ans = 0;
        for (int i = 0; i < MX; i++) ans += dp[i];
        return ans.v;
    }
};