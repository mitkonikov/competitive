#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<vector<int>>> dp, vs;
vector<vector<int>> adj, rev_adj;
vector<int> flow;
unordered_map<string, int> mp;
vector<string> names;
vector<int> compress;

inline bool inMask(int u, int mask) {
    if (compress[u] == -1) return false;
    return mask & (1 << compress[u]);
}

inline int addU(int u, int mask) {
    if (compress[u] == -1) return mask;
    return (mask | (1 << compress[u]));
}

inline void umax(int& a, int b) {
    a = max(a, b);
}

int main() {
    int N;
    cin >> N;
    dp.resize(N, vector<vector<int>>(31, vector<int>(1 << 16, 0)));
    vs.resize(N, vector<vector<int>>(31, vector<int>(1 << 16, 0)));
    flow.resize(N + 10);
    adj.resize(N + 10);
    rev_adj.resize(N + 10);
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
            rev_adj[v].push_back(u);
            p += 3;
        }
    }

    auto calcFlow = [&](int mask) {
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (compress[i] != -1 && ((1 << compress[i]) & mask)) {
                res += flow[i];
            }
        }
        return res;
    };

    // dp[u][time][mask] - result if I have taken all in mask
    //                     after time has passed
    //                     and I'm at u
    vs[add("AA")][4][0] = 1;
    for (int time = 1; time <= 30; time++) {
        for (int u = 0; u < N; u++) {
            for (int mask = 0; mask < (1 << 16); mask++) {
                // Stay
                if (vs[u][time-1][mask]) {
                    umax(dp[u][time][mask], dp[u][time-1][mask] + calcFlow(mask));
                    vs[u][time][mask] = true;
                }
                // Take u now
                if (inMask(u, mask)) {
                    if (vs[u][time-1][mask ^ (1 << compress[u])]) {
                        umax(dp[u][time][mask], dp[u][time-1][mask ^ (1 << compress[u])] + calcFlow(mask));
                        vs[u][time][mask] = true;
                    }
                }
                // Come from v
                for (int v: rev_adj[u]) {
                    if (vs[v][time-1][mask]) {
                        umax(dp[u][time][mask], dp[v][time-1][mask] + calcFlow(mask));
                        vs[u][time][mask] = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << ID); i++) {
        for (int him = 0; him < (1 << ID); him++) {
            if (i & him) continue;
            int mx_me = 0, mx_him = 0;
            for (int u = 0; u < N; u++) {
                umax(mx_me,  dp[u][29][i]);
                umax(mx_him, dp[u][29][him]);
            }
            umax(ans, mx_me + mx_him);
        }
    }
    cout << ans << endl;
    return 0;
}