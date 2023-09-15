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

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<mi> zeros, ones, inversions;

void dfs(int u, int p) {
    visited[u] = true;
    mi zc = 0;
    mi oc = 0;
    for (auto [v, w]: adj[u]) {
        if (v == p) continue;
        // push back w
        zc += (w == 0);
        oc += (w == 1);
        
        if (!visited[v]) {
            dfs(v, u);
        }

        inversions[u] += inversions[v] + (zeros[v] + (w == 0)) * oc;
        zc += zeros[v];
        oc += ones[v];
    }
    zeros[u] = zc;
    ones[u] = oc;
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    visited.resize(N);
    zeros.resize(N);
    ones.resize(N);
    inversions.resize(N);
    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        for (int j = 0; j < S; j++) {
            int v, w;
            cin >> v >> w;
            v--;
            adj[i].push_back({ v, w });
        }
    }
    dfs(0, -1);
    cout << inversions[0] << endl;
    return 0;
}