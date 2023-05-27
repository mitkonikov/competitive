#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> operator+(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	return { (a.first + b.first), (a.second + b.second) };
}

struct CentroidDecomposition {
    vector<vector<int>> G;
    vector<int> sz, pa;
    vector<ll> ans;
    vector<bool> checked;
    vector<vector<map<int, int>>> dicts;
    vector<int> merged;
    vector<int> clear_merge;
    string S;

    CentroidDecomposition(int N) {
        G.resize(N);
        sz.resize(N);
        pa.resize(N);
        ans.resize(N);
        checked.resize(N);
        dicts.resize(N);
        merged.resize(1 << 20);
        for (int i = 0; i < N; ++i) {
            G[i].clear();
        }
    }
    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int dfs(int u, int p) {
        sz[u] = 1;
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            sz[u] += dfs(v, u);
        }
        return sz[u];
    }
    int centroid(int u, int p, int n) {
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            if (sz[v] > n / 2) return centroid(v, u, n);
        }
        return u;
    }
    pair<ll, ll> count_answer(int u, int word) {
        ll through_centroid = 0;
        ll to_centroid = 0;
        for (int i = -1; i < 20; i++) {
            int x = word ^ (i == -1 ? 0 : 1 << i);
            if (x == 0) to_centroid++;
            through_centroid += merged[x];
        }
        return { through_centroid, to_centroid };
    }
    inline int getBit(int u) {
        return (1 << (int)(S[u] - 'a'));
    }
    inline int count_children(int u, int p) {
        int children = 0;
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            children++;
        }
        return children;
    }
    void dfs2(int u, int p, int c, int child = 0, int frq = 0) {
        // add my value to the frq
        if (u != c) frq ^= getBit(u);

        // visit my children
        int cnt = 0;
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            dfs2(v, u, c, (u == c ? cnt : child), frq);
            cnt++;
        }

        // add my frq to the dictionary of my subtree
        if (u != c) {
            dicts[c][child][frq]++;
            merged[frq]++;
            clear_merge.push_back(frq);
        }
    }
    pair<ll, ll> dfs3(int u, int p, int c, int child = 0, int frq = 0) {
        if (u != c) frq ^= getBit(u);

        int cnt = 0;
        pair<ll, ll> result = { 0, 0 };
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            if (u == c) for (auto [frq, occ]: dicts[c][cnt]) merged[frq] -= occ;
            result = result + dfs3(v, u, c, ((u == c) ? cnt : child), frq);
            if (u == c) for (auto [frq, occ]: dicts[c][cnt]) merged[frq] += occ;
            cnt++;
        }

        if (u != c) {
            result = result + count_answer(u, frq ^ getBit(c));
        } else {
            result.first /= 2;
        }

        ans[u] += result.first + result.second;
        return result;
    }
    void build(int u, int p, int d = 0) {
        int n = dfs(u, p);
        int c = centroid(u, p, n);
        pa[c] = p;

        // dicts for every of his children
        dicts[c].clear();
        dicts[c].resize(count_children(c, p));
        
        for (int id: clear_merge) merged[id] = 0;
        clear_merge.clear();

        // fill them up
        dfs2(c, p, c);
        dfs3(c, p, c);
        checked[c] = true;

        for (auto v : G[c]) {
            if (v == p || checked[v]) continue;
            build(v, c, d + 1);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    CentroidDecomposition cd(N + 10);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        cd.addEdge(a, b);
    }
    cin >> cd.S;
    cd.S = "@" + cd.S;
    cd.build(1, 0);
    for (int i = 1; i <= N; i++) {
        cout << cd.ans[i] + 1 << " ";
    } cout << endl;
}