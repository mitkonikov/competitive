#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<vector<ll>>> dp;
vector<vector<int>> adj;
vector<int> flow;
unordered_map<string, int> mp;
vector<string> names;
vector<int> compress;

inline bool inMask(int u, ll mask) {
    if (compress[u] == -1) return true;
    return mask & (1 << compress[u]);
}

inline ll addU(int u, ll mask) {
    if (compress[u] == -1) return mask;
    return (mask | (1 << compress[u]));
}

ll dfs(int u, int time, ll mask) {
    if (time <= 0) return 0;
    if (dp[u][time][mask] != -1) return dp[u][time][mask];
    ll f = (inMask(u, mask) ? 0 : flow[u] * (time - 1));
    assert(f >= 0);
    ll r = f;
    ll d = 0;
    for (auto v: adj[u]) {
        r = max(r, f + dfs(v, time - 2, addU(u, mask)));
    }
    for (auto v: adj[u]) {
        d = max(d, dfs(v, time - 1, mask));
    }
    return dp[u][time][mask] = max(r, d);
}

int main() {
    int N;
    cin >> N;
    dp.resize(N, vector<vector<ll>>(31, vector<ll>(1 << 16, -1)));
    flow.resize(N + 10);
    adj.resize(N + 10);
    names.resize(N + 10);
    compress.resize(N + 10, -1);
    int id = 0;
    auto add = [&](string name) {
        auto it = mp.find(name);
        if (it == mp.end()) {
            mp[name] = id++;
            names[id-1] = name;
            return id-1;
        }
        return it->second;
    };
    int ID = 0;
    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        int u = add(name);
        int f; cin >> f;
        flow[u] = f;
        if (flow[u] > 0) { compress[u] = ID++; }
        string line;
        getline(cin, line);
        getline(cin, line);
        int p = 0;
        while (p < line.size()) {
            string v_name = line.substr(p, 2);
            int v = add(v_name);
            adj[u].push_back(v);
            p += 3;
        }
    }
    cout << dfs(add("AA"), 30, 0) << endl;
    return 0;
}