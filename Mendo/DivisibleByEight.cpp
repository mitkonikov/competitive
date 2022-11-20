#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int mod=1e9 + 7;
struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<mi>> prefix_sum(n + 1, vector<mi>(10, 0));
    vector<mi> last_power(10, 0);
    vector<int> div;
    for (int i = 0; i < 1000; i++) {
        if (i % 8 == 0) {
            div.push_back(i);
        }
    }
    mi ans = 0;
    prefix_sum[0][s[0] - '0']++;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + ((s[i] - '0') == j);
        }
    }
    vector<mi> powers(n + 10, 0);
    powers[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers[i] = powers[i-1] * 2;
    }
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 8 == 0) {
            ans++;
        }
        if (i > 0) {
            for (int j = 0; j < 10; j++) {
                if ((j * 10 + (s[i] - '0')) % 8 == 0) {
                    ans += prefix_sum[i-1][j];
                }
            }
            for (int d: div) {
                int front_int = d / 100;
                int back_int = d % 10;
                if (((d / 10) % 10) == s[i] - '0') {
                    mi back = prefix_sum[n][back_int] - prefix_sum[i][back_int];
                    ans += (mi)last_power[front_int] * back;
                }
            }
        }
        last_power[s[i] - '0'] += powers[i];
    }
    cout << ans << endl;
    return 0;
}