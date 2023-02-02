#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
const int LOG = 31;
 
struct BitwiseGauss {
    int basis[LOG];
    bool sorted = false;
 
    BitwiseGauss() {
        memset(basis, 0, LOG * sizeof(int));
    }
    
    void insertVector(int mask) {
        sorted = false;
        for (int i = LOG - 1; i >= 0; i--) {
            if ((mask & 1 << i) == 0) continue;
    
            if (!basis[i]) {
                basis[i] = mask;
                return;
            }
    
            mask ^= basis[i];
        }
    }
 
    vector<ll> getX() {
        vector<ll> result;
        for (ll i = 0; i < LOG; i++) {
            if (basis[i]) result.push_back(i);
        }
        if (!sorted) {
            for (int i = LOG - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    if ((basis[i] ^ basis[j]) < basis[i]) {
                        basis[i] ^= basis[j];
                    }
                }
            }
            sorted = true;
        }
        return result;
    }
 
    int GetMax() {
        auto v = getX();
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans ^= basis[v[i]];
        }
        return ans;
    }
 
    void merge(BitwiseGauss& other) {
        for (int i = 0; i < LOG; i++) {
            if (other.basis[i]) {
                insertVector(other.basis[i]);
            }
        }
    }
};
 
vector<vector<int>> adj;
vector<vector<int>> adj_no_parent;
vector<int> val;
vector<BitwiseGauss> without_me, my_subtree;
vector<int> parent;
int N;
 
void dfs1(int u, int p) {
    my_subtree[u].insertVector(val[u]);
    for (auto v: adj[u]) {
        if (v == p) continue;
        adj_no_parent[u].push_back(v);
        dfs1(v, u);
        my_subtree[u].merge(my_subtree[v]);
    }
    vector<BitwiseGauss> suff(adj[u].size());
    int C = adj[u].size();
    for (int i = C - 1; i >= 0; i--) {
        if (i+1 < C) suff[i] = suff[i+1];
        if (adj[u][i] == p) continue;
        suff[i].merge(my_subtree[adj[u][i]]);
    }
    BitwiseGauss pref;
    for (int i = 0; i < C; i++) {
        if (adj[u][i] == p) continue;
        without_me[adj[u][i]].merge(pref);
        if (i+1 < C) without_me[adj[u][i]].merge(suff[i+1]);
        pref.merge(my_subtree[adj[u][i]]);
    }
}
 
void dfs2(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        without_me[v].merge(without_me[u]);
        without_me[v].insertVector(val[u]);
        dfs2(v, u);
    }
}
 
vector<int> timer_in, timer_out;
int t = 0;
 
void dfs3(int u, int p) {
    parent[u] = p;
    timer_in[u] = ++t;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs3(v, u);
    }
    timer_out[u] = ++t;
}
 
// Is V ancestor of U
inline bool ancestor(int u, int v) {
    return (timer_in[v] >= timer_in[u] && timer_out[v] <= timer_out[u]);
}
 
void testCase() {
    t = 0;
    cin >> N;
    adj.clear();
    adj_no_parent.clear();
    val.clear();
    without_me.clear();
    my_subtree.clear();
    timer_in.clear();
    timer_out.clear();
    parent.clear();
    adj.resize(N);
    adj_no_parent.resize(N);
    val.resize(N);
    without_me.resize(N);
    my_subtree.resize(N);
    timer_in.resize(N);
    timer_out.resize(N);
    parent.resize(N);
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);
    int Q;
    cin >> Q;
    while (Q--) {
        int r, v;
        cin >> r >> v;
        r--; v--;
        if (r == v) {
            cout << my_subtree[0].GetMax() << endl;
            continue;
        }
        if (ancestor(r, v) || !ancestor(v, r)) {
            cout << my_subtree[v].GetMax() << endl;
            continue;
        }
        // at vertex v, there is a child without whom the answer is given
        int L = 0, R = adj_no_parent[v].size();
        while (R - L > 1) {
            int mid = (R + L) / 2;
            int mid_node = adj_no_parent[v][mid];
            if (timer_in[mid_node] > timer_out[r]) {
                R = mid;
            } else {
                L = mid;
            }
        }
        bool ok = false;
        for (int off = max(0, R - 3); off <= min(R + 3, (int)adj_no_parent[v].size() - 1); off++) {
            int w = adj_no_parent[v][off];
            if (w == r || ancestor(w, r)) {
                cout << without_me[w].GetMax() << endl;
                ok = true;
                break;
            }
        }
        assert(ok);
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t;
    cin >> t;
 
    while (t--) {
        testCase();
    }
 
    cout << flush;
    return 0;
}