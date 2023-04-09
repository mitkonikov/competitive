#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class RAMSticks {
    const int INF = 1e9;
#define N 64

    struct edge {
        int u, v, w;
    };

    int n, n_x;
    vector<vector<edge>> g;
    vector<int> lab;
    vector<int> match, slack, st, pa, S, vis;
    vector<vector<int>> flower_from;
    vector<int> flower[N * 2];
    queue<int> q;

    int e_delta(const edge &e) {
        return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2;
    }

    void update_slack(int u, int x) {
        if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x]))
            slack[x] = u;
    }

    void set_slack(int x) {
        slack[x] = 0;
        for (int u = 1; u <= n; ++u)
            if (g[u][x].w > 0 && st[u] != x && S[st[u]] == 0)
                update_slack(u, x);
    }

    void q_push(int x) {
        if (x <= n)
            q.push(x);
        else
            for (int i : flower[x]) q_push(i);
    }

    void set_st(int x, int b) {
        st[x] = b;
        if (x > n)
            for (int i : flower[x]) set_st(i, b);
    }

    int get_pr(int b, int xr) {
        int pr =
            find(flower[b].begin(), flower[b].end(), xr) - flower[b].begin();
        if (pr % 2 == 1) {
            reverse(flower[b].begin() + 1, flower[b].end());
            return (int)flower[b].size() - pr;
        } else
            return pr;
    }

    void set_match(int u, int v) {
        match[u] = g[u][v].v;
        if (u <= n) return;
        edge e = g[u][v];
        int xr = flower_from[u][e.u], pr = get_pr(u, xr);
        for (int i = 0; i < pr; ++i) set_match(flower[u][i], flower[u][i ^ 1]);
        set_match(xr, v);
        rotate(flower[u].begin(), flower[u].begin() + pr, flower[u].end());
    }

    void augment(int u, int v) {
        for (;;) {
            int xnv = st[match[u]];
            set_match(u, v);
            if (!xnv) return;
            set_match(xnv, st[pa[xnv]]);
            u = st[pa[xnv]], v = xnv;
        }
    }

    int get_lca(int u, int v) {
        static int t = 0;
        for (++t; u || v; swap(u, v)) {
            if (u == 0) continue;
            if (vis[u] == t) return u;
            vis[u] = t;
            u = st[match[u]];
            if (u) u = st[pa[u]];
        }
        return 0;
    }

    void add_blossom(int u, int lca, int v) {
        int b = n + 1;
        while (b <= n_x && st[b]) ++b;
        if (b > n_x) ++n_x;
        lab[b] = 0, S[b] = 0;
        match[b] = match[lca];
        flower[b].clear();
        flower[b].push_back(lca);
        for (int x = u, y; x != lca; x = st[pa[y]])
            flower[b].push_back(x), flower[b].push_back(y = st[match[x]]),
                q_push(y);
        reverse(flower[b].begin() + 1, flower[b].end());
        for (int x = v, y; x != lca; x = st[pa[y]])
            flower[b].push_back(x), flower[b].push_back(y = st[match[x]]),
                q_push(y);
        set_st(b, b);
        for (int x = 1; x <= n_x; ++x) g[b][x].w = g[x][b].w = 0;
        for (int x = 1; x <= n; ++x) flower_from[b][x] = 0;
        for (size_t i = 0; i < flower[b].size(); ++i) {
            int xs = flower[b][i];
            for (int x = 1; x <= n_x; ++x)
                if (g[b][x].w == 0 || e_delta(g[xs][x]) < e_delta(g[b][x]))
                    g[b][x] = g[xs][x], g[x][b] = g[x][xs];
            for (int x = 1; x <= n; ++x)
                if (flower_from[xs][x]) flower_from[b][x] = xs;
        }
        set_slack(b);
    }

    void expand_blossom(int b) {
        for (int i : flower[b]) set_st(i, i);
        int xr = flower_from[b][g[b][pa[b]].u];
        int pr = get_pr(b, xr);
        for (int i = 0; i < pr; i += 2) {
            int xs = flower[b][i], xns = flower[b][i + 1];
            pa[xs] = g[xns][xs].u;
            S[xs] = 1;
            S[xns] = 0;
            slack[xs] = 0;
            set_slack(xns);
            q_push(xns);
        }
        S[xr] = 1, pa[xr] = pa[b];
        for (int i = pr + 1; i < flower[b].size(); ++i) {
            int xs = flower[b][i];
            S[xs] = -1;
            set_slack(xs);
        }
        st[b] = 0;
    }

    bool on_found_edge(const edge &e) {
        int u = st[e.u], v = st[e.v];
        if (S[v] == -1) {
            pa[v] = e.u;
            S[v] = 1;
            int nu = st[match[v]];
            slack[v] = slack[nu] = 0;
            S[nu] = 0;
            q_push(nu);
        } else if (S[v] == 0) {
            int lca = get_lca(u, v);
            if (!lca) {
                augment(u, v);
                augment(v, u);
                return true;
            } else {
                add_blossom(u, lca, v);
            }
        }
        return false;
    }

    bool matching() {
        fill(S.begin(), S.end(), -1);
        fill(slack.begin(), slack.end(), 0);
        q = queue<int>();
        for (int x = 1; x <= n_x; ++x)
            if (st[x] == x && !match[x]) {
                pa[x] = 0;
                S[x] = 0;
                q_push(x);
            }
        if (q.empty()) return false;
        for (;;) {
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (S[st[u]] == 1) continue;
                for (int v = 1; v <= n; ++v)
                    if (g[u][v].w > 0 && st[u] != st[v]) {
                        if (e_delta(g[u][v]) == 0) {
                            if (on_found_edge(g[u][v])) return true;
                        } else
                            update_slack(u, st[v]);
                    }
            }
            int d = INF;
            for (int b = n + 1; b <= n_x; ++b)
                if (st[b] == b && S[b] == 1) d = min(d, lab[b] / 2);
            for (int x = 1; x <= n_x; ++x)
                if (st[x] == x && slack[x]) {
                    if (S[x] == -1)
                        d = min(d, e_delta(g[slack[x]][x]));
                    else if (S[x] == 0)
                        d = min(d, e_delta(g[slack[x]][x]) / 2);
                }
            for (int u = 1; u <= n; ++u) {
                if (S[st[u]] == 0) {
                    if (lab[u] <= d) return false;
                    lab[u] -= d;
                } else if (S[st[u]] == 1)
                    lab[u] += d;
            }
            for (int b = n + 1; b <= n_x; ++b)
                if (st[b] == b) {
                    if (S[st[b]] == 0)
                        lab[b] += d * 2;
                    else if (S[st[b]] == 1)
                        lab[b] -= d * 2;
                }
            q = queue<int>();
            for (int x = 1; x <= n_x; ++x)
                if (st[x] == x && slack[x] && st[slack[x]] != x &&
                    e_delta(g[slack[x]][x]) == 0)
                    if (on_found_edge(g[slack[x]][x])) return true;
            for (int b = n + 1; b <= n_x; ++b)
                if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);
        }
    }

    tuple<long long, int> solve() {
        n_x = n;
        int n_matches = 0;
        long long tot_weight = 0;
        for (int u = 0; u <= n; ++u) {
            st[u] = u;
            flower[u].clear();
        }
        int w_max = 0;
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v) {
                flower_from[u][v] = (u == v ? u : 0);
                w_max = max(w_max, g[u][v].w);
            }
        for (int u = 1; u <= n; ++u) lab[u] = w_max;
        while (matching()) ++n_matches;
        for (int u = 1; u <= n; ++u)
            if (match[u] && match[u] < u) tot_weight += g[u][match[u]].w;
        return {tot_weight, n_matches};
    }

    void add_edge(int u, int v, int w) { g[u][v].w = g[v][u].w = w; }

    void init(int _n) {
        n = _n;
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v) g[u][v] = edge{u, v, 0};
    }

   public:
    string pairRAM(string originalPosition,
                   vector<string> pairingEfficiencyList) {
        g.clear();
        lab.clear();
        match.clear();
        slack.clear();
        st.clear();
        pa.clear();
        flower_from.clear();
        S.clear();
        vis.clear();
        g.resize(N * 2, vector<edge>(N * 2));
        lab.resize(N * 2);
        match.resize(N * 2);
        slack.resize(N * 2);
        st.resize(N * 2);
        pa.resize(N * 2);
        flower_from.resize(N * 2, vector<int>(N + 1));
        S.resize(N * 2);
        vis.resize(N * 2);
        for (int i = 0; i < N * 2; i++) flower[i].clear();
        while (!q.empty()) q.pop();

        auto split = [](string &s) {
            int prev = 0;
            vector<int> res;
            s += ";";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ';') {
                    res.push_back(stoi(s.substr(prev, i - prev + 1)));
                    prev = i + 1;
                }
            }
            return res;
        };

        int nn = pairingEfficiencyList.size();
        vector<vector<int>> adj(nn, vector<int>(nn, 0));

        for (int i = 0; i < nn; i++) {
            auto vec = split(pairingEfficiencyList[i]);
            vec.insert(vec.begin() + i, 0);
            adj[i] = vec;
        }

        n = nn;
        init(n);
        for (int i = 0; i < nn; i++) {
            for (int j = i + 1; j < nn; j++) {
                add_edge(i + 1, j + 1, adj[i][j] + adj[j][i]);
            }
        }

        auto [tot_weight, n_matches] = solve();
        // cout << "!" << tot_weight << " " << n_matches << endl;
        map<char, char> mp;
        for (int u = 1; u <= n; ++u)
            if (match[u] && match[u] < u) {
                mp[originalPosition[u - 1]] = originalPosition[match[u] - 1];
                mp[originalPosition[match[u] - 1]] = originalPosition[u - 1];
            }

        string ans = "";
        for (int i = 0; i < nn; i++) {
            ans += mp[originalPosition[i]];
        }

        return ans;
    }
};

// #include <iostream>
// int main() {
//     RAMSticks rs;
//     string a = rs.pairRAM("mdnrlaiepo", {"79;111;615;549;33;972;203;995;418",
//                                          "299;626;270;160;707;44;889;348;322",
//                                          "369;982;142;919;883;387;386;472;891",
//                                          "533;396;660;888;610;698;573;106;636",
//                                          "997;964;831;520;278;442;650;738;733",
//                                          "244;959;309;448;265;534;311;562;348",
//                                          "12;808;426;594;323;21;386;631;604",
//                                          "648;137;62;649;643;341;478;362;696",
//                                          "940;362;624;724;286;756;502;23;604",
//                                          "63;978;693;22;987;379;258;644;468"});
//     cout << a << endl;
//     return 0;
// }