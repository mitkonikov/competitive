#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<int> dp;
vector<bool> visited;
vector<bool> st;

int cycle = -1;

int dfs(int u) {
    if (st[u]) {
        cycle = u;
        return 0;
    }
    if (dp[u] != -1) return dp[u];
    st[u] = true;
    int me = 0;
    for (auto v: adj[u]) {
        me = max(me, dfs(v));
    }
    st[u] = false;
    return dp[u] = me + 1;
}

void dfs2(int u, int t) {
    dp[u] = t;
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v]) continue;
        dp[v] = t;
        dfs2(v, t);
    }
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    dp.resize(N, -1);
    visited.resize(N, false);
    st.resize(N, false);
    for (int i = 0; i < N; i++) {
        int to;
        cin >> to;
        to--;
        adj[i].push_back(to);
    }
    int ans = 1;
    for (int i = 0; i < N; i++) {
        cycle = -1;
        int t = dfs(i);
        ans = max(ans, t);
        if (cycle != -1) dfs2(cycle, dp[cycle]);
    }
    cout << ans << endl;
    return 0;
}