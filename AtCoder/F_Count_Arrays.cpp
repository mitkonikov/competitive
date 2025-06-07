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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<vector<int>> rev(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        rev[A[i]].push_back(i);
    }
    vector<vector<int>> cycles;
    vector<bool> visited(N);
    vector<vector<mi>> dp(N, vector<mi>(M + 10, 0));
    mi ans = 1;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        int t = i;
        do {
            visited[t] = true;
            t = A[t];
        } while (!visited[t]);
        cycles.push_back({ });
        int tt = t;
        do {
            cycles.back().push_back(tt);
            tt = A[tt];
        } while (tt != t);
        auto& cycle = cycles.back();
        auto dfs = [&](auto&& dfs, int u, int p) {
            visited[u] = true;
            if (rev[u].empty()) {
                for (int m = 1; m <= M; m++) {
                    dp[u][m] = m;
                }
                return;
            }
            for (auto v : rev[u]) {
                if (v == p) continue;
                dfs(dfs, v, u);
            }
            for (int m = 1; m <= M; m++) {
                mi cur = 1;
                for (auto v : rev[u]) {
                    if (v == p) continue;
                    cur *= dp[v][m];
                }
                dp[u][m] = cur;
                dp[u][m] += dp[u][m-1];
            }
        };
        for (int c = 0; c < cycle.size(); c++) {
            int u = cycle[c];
            int p = cycle[(c-1+cycle.size())%cycle.size()];
            dfs(dfs, u, p);
        }
        mi cycle_ans = 0;
        for (int m = 1; m <= M; m++) {
            mi current_ans = 1;
            for (int c = 0; c < cycle.size(); c++) {
                int u = cycle[c];
                current_ans *= dp[u][m] - dp[u][m-1];
            }
            cycle_ans += current_ans;
        }
        ans *= cycle_ans;
    }
    cout << ans << endl;
    return 0;
}