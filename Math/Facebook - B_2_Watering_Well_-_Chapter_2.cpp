#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int mod=1000000007;
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

void testCase() {
    int n;
    cin >> n;

    vector<vector<mi>> trees(n);
    vector<mi> sum(2);
    vector<mi> sq(2);
    for (int i = 0; i < n; i++) {
        vector<mi> point(2);
        for (int j = 0; j < 2; j++) {
            cin >> point[j];
            sum[j] += point[j];
            sq[j] += point[j] * point[j];
        }
        trees[i] = point;
    }

    int q;
    cin >> q;

    mi answer = 0;
    for (int i = 0; i < q; i++) {
        mi px, py;
        cin >> px >> py;
        mi X = px * px * n + sq[0] - mi(2) * px * sum[0];
        mi Y = py * py * n + sq[1] - mi(2) * py * sum[1];
        answer += X + Y;
    }
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << (i+1) << ": ";
        testCase();
    }

    return 0;
}