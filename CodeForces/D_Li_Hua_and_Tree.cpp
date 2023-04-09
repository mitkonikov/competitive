#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> imp;
vector<ll> sub;
vector<int> subsize;

struct subtree {
    int size, id;
    bool operator<(const subtree& other) const {
        if (size == other.size) return (id > other.id);
        return size < other.size;
    }
};

vector<vector<int>> adj_init;
vector<int> parent;
vector<set<int>> adj;
vector<priority_queue<subtree, vector<subtree>, less<subtree>>> pqs;

void dfs1(int u, int p) {
    sub[u] += imp[u];
    subsize[u]++;
    if (p != -1) parent[u] = p;
    for (auto v: adj_init[u]) {
        if (v == p) continue;
        adj[u].insert(v);
        dfs1(v, u);
        sub[u] += sub[v];
        subsize[u] += subsize[v];
        pqs[u].push({ subsize[v], v });
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    imp.resize(N);
    sub.resize(N);
    adj_init.resize(N);
    for (int i = 0; i < N; i++) cin >> imp[i];
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_init[u].push_back(v);
        adj_init[v].push_back(u);
    }
    parent.resize(N, -1);
    adj.resize(N);
    pqs.resize(N);
    subsize.resize(N);
    dfs1(0, -1);
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            cout << sub[x] << endl;
        } else {
            if (adj[x].empty()) continue;
            // find the heaviest element
            while (true) {
                assert(pqs[x].size() > 0);
                auto heavy = pqs[x].top();
                pqs[x].pop();
                // check it
                if (adj[x].count(heavy.id) == 0) continue;
                // rotate it
                const int hid = heavy.id;

                // delete x from px
                int px = parent[x];
                adj[px].erase(x);
                sub[px] -= sub[x];
                subsize[px] -= subsize[x];

                // delete hid from x
                sub[x] -= sub[hid];
                subsize[x] -= subsize[hid];
                adj[x].erase(hid);

                // add x to hid
                parent[x] = hid;
                sub[hid] += sub[x];
                subsize[hid] += subsize[x];
                adj[hid].insert(x);
                pqs[hid].push({ subsize[x], x });

                // add hid to px
                adj[px].insert(hid);
                sub[px] += sub[hid];
                subsize[px] += subsize[hid];
                parent[hid] = px;
                pqs[px].push({ subsize[hid], hid });

                break;
            }
        }
    }
    return 0;
}