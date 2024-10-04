#include "bits/stdc++.h"
#define ll long long
 
const int mod = 1e9 + 7;
struct mi {
    int v;
    mi() { v=0; }
    mi(ll _v) { v = int(-mod<=_v&&_v<mod?_v:_v%mod); if (v<0) v += mod; }
    explicit operator int() const { return v; }
    friend bool operator==(const mi& a, const mi& b) { return (a.v == b.v); }
    mi& operator+=(const mi &m) { if ((v += m.v) >= mod) v-=mod; return *this; }
    mi& operator-=(const mi &m) { if ((v -= m.v) < 0) v+=mod; return *this; }
    mi& operator*=(const mi &m) { v=((ll)(v) * m.v) % mod; return *this; }
};
 
using namespace std;
 
vector<vector<int>> adj;
 
int mx_height = 1;
 
void dfs(int u, int p, int d) {
    mx_height = max(mx_height, d);
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}
 
int main() {
    int N;
    cin >> N;
    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    int depth = INT_MAX;
    for (int i = 0; i < N; i++) {
        mx_height = 1;
        dfs(i, -1, 0);
        if (mx_height < depth) {
            depth = mx_height;
            ans.clear();
        }
        if (mx_height == depth) {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}