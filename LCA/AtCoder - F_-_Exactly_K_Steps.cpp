#include <bits/stdc++.h>

using namespace std;

int n, q, l;
vector<vector<int>> adj;
vector<vector<int>> upA, upB;
vector<int> depthsRoot, depthsA, depthsB;

void dfs(int v, int depth, vector<int> &depth_vec, int p = -1) {
    depth_vec[v] = depth;

    for (auto u: adj[v]) {
        if (u == p) continue;
        dfs(u, depth+1, depth_vec, v);
    }
}

void compute_lifting(int v, int p, vector<vector<int>> &up) {
    up[v][0] = p;
    for (int k = 1; k <= l; k++) {
        up[v][k] = up[up[v][k-1]][k-1];
    }

    for (auto u: adj[v]) {
        if (u == p) continue;
        compute_lifting(u, v, up);
    }
}

int far(int v, vector<int> &depth_vec) {
    dfs(v, 0, depth_vec, -1);

    int result = -1;
    int max_depth = 0;
    for (int i = 0; i < depth_vec.size(); i++) {
        if (i != v && depth_vec[i] > max_depth) {
            max_depth = depth_vec[i];
            result = i;
        }
    }

    return result;
}

int lifting(int v, int d, vector<vector<int>> &up) {
    for (int i = l; i >= 0; i--) {
        if (((1 << i) & d) > 0) {
            v = up[v][i];
        }
    }

    return v;
}

int main() {
    cin >> n;

    adj.resize(n);
    depthsRoot.resize(n);
    depthsA.resize(n);
    depthsB.resize(n);

    l = ceil(log2(n));

    upA.resize(n, vector<int>(l+1));
    upB.resize(n, vector<int>(l+1));
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int A = far(0, depthsRoot);
    int B = far(A, depthsA);
    dfs(B, 0, depthsB);

    for (int i = 0; i <= l; i++) {
        upA[A][i] = A;
        upB[B][i] = B;
    }

    compute_lifting(A, A, upA);
    compute_lifting(B, B, upB);
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, d;
        cin >> u >> d;
        u--;

        if (depthsA[u] < d && depthsB[u] < d) {
            cout << -1 << "\n";
            continue;
        }

        if (depthsA[u] > depthsB[u]) {
            cout << lifting(u, d, upA) + 1 << "\n";
        } else {
            cout << lifting(u, d, upB) + 1 << "\n";
        }
    }
    
    cout << flush;
    return 0;
}