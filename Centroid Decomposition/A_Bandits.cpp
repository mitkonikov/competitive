#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define fwd(i,a,b) for(int i=(a); i<(b);i++)
#define rep(i,n) fwd(i,0,n)
#define all(X) (X).begin(), (X).end()
#define sz(X)((int)(X).size())
#define st first
#define nd second
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pii;

#ifdef LOC
auto& operator<<(auto& out, pair<auto, auto> a) {return out<<"("<<a.st<<", "<<a.nd<<")";}
auto& operator<<(auto& out, auto a) {
    out<<"{";
    for(auto b:a) out<<b<<", ";
    return out<<"}";
}

void dump(auto... x) {((cerr<<x<<", "),...)<<"\n";}
#define debug(x...) cerr<<"[" #x "]: ", dump(x)
#else
#define debug(...) ;
#endif 
 
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int CNT = 0;
const int inf = 1e9 + 2137;
 
const int LCALOG = 17;
 
struct LCA {
    vi depth;
    vi ord, sub;
    vector<vi> jmp;
    int kont = 0;
    int N = 0;
    LCA() {}
    void dfs(int v, vector<vector<pii>>& G) {
        ord[v] = kont ++;
        for (auto [u, w] : G[v])
            if (depth[u] == -1) {
                depth[u] = depth[v] + 1;
                jmp[0][u] = v;
                dfs(u, G);
                sub[v] += sub[u];
            }
    }
    LCA(vector<vector<pii>>& G, int _N) : N(_N) {
        jmp = vector<vi>(LCALOG, vi(N));
        depth = vi(N, -1);
        ord = vi(N);
        sub = vi(N, 1);
        depth[0] = 0;
        jmp[0][0] = 0;
        dfs(0, G);
        fwd(i, 1, LCALOG)
            rep(j, N)
                jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
    }
    int lca(int v, int u) {
        if (depth[u] > depth[v])
            swap(v, u);
        for (int i = LCALOG - 1; i >= 0; -- i)
            if ((1 << i) <= depth[v] - depth[u])
                v = jmp[i][v];
        if (v == u)
            return v;
        for (int i = LCALOG - 1; i >= 0; -- i)
            if (jmp[i][v] != jmp[i][u]) {
                v = jmp[i][v];
                u = jmp[i][u];
            }
        return jmp[0][v];
    }
    bool under(int v, int u) {
        if (ord[v] >= ord[u] && ord[v] + sub[v] <= ord[u] + sub[u])
            return true;
        return false;
    }
    bool on_path2(int v, int u, int x) {
        if (under(v, x) && under(x, u))
            return true;
        return false;
    }
    bool on_path(int v, int u, int x) {
        int lc = lca(v, u);
        if (on_path2(v, lc, x) || on_path2(u, lc, x))
            return true;
        return false;
    }
};
 
struct CentroidTree {
    vector<vi> c_tree, ind, dists, subtree, neigh, dir;
    vector<vector<pair<ll, pii>>> updists;
    vector<Tree<pair<ll, int> > > stats;
    vector<vector<Tree<pair<ll, int> > > > stats2;
    vector<set<pii>> sons;
    vi par, depth, size;
    int root; // Centroid Root
    LCA lca;
    CentroidTree() {
 
    }
    
    // G - our graph
    CentroidTree(vector<vector<pii>>& G, int N): 
        sons(N), c_tree(N), stats(N), stats2(N),
        ind(N), dists(N), updists(N), subtree(N),
        neigh(N), dir(N), par(N, -2), depth(N), size(N) {
        
        root = decomp(G, 0, 0);
        lca = LCA(G, N);
    };

    void dfs(vector<vector<pii>>& G, int v, int p) {
        size[v] = 1;
        for (auto [e, w]: G[v])
            if (e != p && par[e] == -2) // if it's never visited before.
                dfs(G, e, v), size[v] += size[e];
    }
    
    void layer(vector<vector<pii>>& G, int u, int parent, int centroid, ll distance_from_centroid, int dude = -1) {
        if (dude == -1 && u != centroid) {
            dude = sz(stats2[centroid]); // what tree is this dude on, but the dude is neigh, the subtree of the centroid
            stats2[centroid].push_back(Tree<pair<ll, int>>());
            sons[centroid].insert(make_pair(u, dude)); // who the fuck is this dude?
        }

        ind[u].push_back(sz(subtree[centroid])); // where is u in the subtree of the centroid
        
        subtree[centroid].push_back(u); // Push u to the subtree of the centroid
        
        dists[centroid].push_back(distance_from_centroid); // Distances to the centroid?
        
        updists[u].push_back(make_pair(distance_from_centroid, make_pair(centroid, dude)));
        
        dir[centroid].push_back(sz(neigh[centroid]) - 1); // ?

        for (auto [e, w]: G[u]) {
            if (e != parent && par[e] == -2) {
                if (u == centroid) neigh[centroid].push_back(e);
                layer(G, e, u, centroid, distance_from_centroid + w, dude);
            }
        }
    }
    
    int decomp(vector<vector<pii>>& G, int v, int d) {
        dfs(G, v, -1);
        int p = -1, s = size[v];
        loop:
            for(auto [e, w] : G[v]) {
                if (e != p && par[e] == -2 && size[e] > s / 2) {
                    p = v; v = e; goto loop;
                }
            }
        par[v] = -1;  // Centroid root
        size[v] = s;  // Size of the centroid in the G
        depth[v] = d; // depth of centroid in the CT
        layer(G, v, -1, v, 0);
        for (auto [e, w] : G[v]) {
            if (par[e] == -2) {
                int j = decomp(G, e, d + 1);
                c_tree[v].push_back(j);  // In the CT
                par[j] = v;              // In the CT
            }
        }
        return v;
    }
    
    // On distance d from vertex v
    void update(int v, ll d) {
        for (auto xd : updists[v]) { // LOG(N)
            auto [centroid, my_dude] = xd.nd;
            ll w = xd.st; // the distance from this centroid
            stats[centroid].insert(make_pair(- (d - w), ++ CNT));
            if (my_dude != -1) // if the centroid is not his neigh
                stats2[centroid][my_dude].insert(make_pair(- (d - w), ++ CNT));
        }
    }
    
    int query(int v, ll d, int bad) {
        int ans = 0;
        for (auto xd : updists[v]) {
            auto [centroid, subtree] = xd.nd;
            ll w = xd.st;         // distance from the centroid
            ll reald = w + d;     // distance to the other node
            if (subtree != -1) {  // if my dude is not the centroid
                if (!lca.on_path(v, centroid, bad)) {
                    // our partner is on the other side
                    ans += stats[centroid].order_of_key(make_pair(-reald, inf));
                    ans -= stats2[centroid][subtree].order_of_key(make_pair(-reald, inf));
                }
            } else {
                ans += stats[centroid].order_of_key(make_pair(-reald, inf));
                auto xd = sons[centroid].lower_bound(make_pair(bad, -1));
                if (xd != end(sons[centroid])) {
                    if ((*xd).st == bad) {
                        ans -= stats2[centroid][(*xd).nd].order_of_key(make_pair(-reald, inf));
                    }
                }
            }
        }
        return ans;
    }
};
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pii>> g(n);
    vector<pii> ep(n - 1);
    vi wei(n - 1);
    rep(i, n - 1) {
        int v, u, w;
        cin >> v >> u >> w;
        -- v, -- u;
        ep[i] = make_pair(v, u);
        g[v].push_back(make_pair(u, w));
        g[u].push_back(make_pair(v, w));
        wei[i] = w;
    }
    int q;
    cin >> q;
    CentroidTree ct(g, n);
    rep(i, q) {
        char type;
        cin >> type;
        if (type == '?') {
            int e;
            cin >> e;
            --e;
            int ans =
                ct.query(ep[e].st, wei[e], ep[e].nd) +
                ct.query(ep[e].nd, wei[e], ep[e].st);
            cout << ans << '\n';
        } else {
            int v, w;
            cin >> v >> w;
            --v;
            ct.update(v, w);
        }
    }
}