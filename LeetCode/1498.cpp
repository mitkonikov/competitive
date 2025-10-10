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
    int numSubseq(vector<int>& nums, int target) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        mi ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            int L = 0, R = i + 1;
            while (R - L > 1) {
                int M = (R + L) / 2;
                if (nums[i] + nums[M] <= target) {
                    L = M;
                } else {
                    R = M;
                }
            }
            if (nums[i] + nums[L] <= target) {
                if (i == L) {
                    ans++;
                    L--;
                }
                if (L < 0) continue;
                // sum from 0 to L of 2^(i-1-x)
                mi cur = pow(mi(2), i) - pow(mi(2), i - L - 1);
                ans += cur;
            }
        }
        return ans.v;
    }
};