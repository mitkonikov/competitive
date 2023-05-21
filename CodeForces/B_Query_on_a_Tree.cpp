#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
inline char gc() { // like getchar()
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++]; // returns 0 on EOF
}
 
int readInt() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -readInt();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}
 
vector<pair<int, int>> edges;
vector<vector<int>> adj;
vector<vector<int>> queries;
vector<map<int, vector<int>>> adj2;
vector<bool> visited;
vector<int> visited_now;
vector<int> parent;
ll ans = 0;

void dfs1(int u, int p = -1) {
    parent[u] = p;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
    }
}
 
int dfs(int u, int q, int p = -1) {
    int subsize = 1;
    visited[u] = true;
    visited_now.push_back(u);
    for (auto v: adj2[q][u]) {
        if (v == p) continue;
        subsize += dfs(v, q, u);
    }
    return subsize;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N = readInt();
    edges.resize(N - 1);
    adj.resize(N);
    parent.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u = readInt() - 1;
        int v = readInt() - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = { u, v };
    }
    int Q = readInt();
    queries.resize(Q);
    adj2.resize(Q);
    for (int i = 0; i < Q; i++) {
        int K = readInt();
        queries[i].reserve(K);
        for (int j = 0; j < K; j++) {
            int u = readInt() - 1;
            queries[i].push_back(u);
        }
    }
    // root the tree
    dfs1(0);
    vector<bool> in_query(N);
    for (int i = 0; i < Q; i++) {
        for (auto el: queries[i]) in_query[el] = true;
        for (int j = 0; j < queries[i].size(); j++) {
            int u = queries[i][j];
            int pu = parent[u];
            if (pu != -1 && in_query[pu]) {
                adj2[i][pu].push_back(u);
                adj2[i][u].push_back(pu);
            }
        }
        for (auto el: queries[i]) in_query[el] = false;
    }
    // answer each query
    visited.resize(N);
    for (int i = 0; i < Q; i++) {
        ans = 0;
        for (auto u: queries[i]) {
            if (visited[u]) continue;
            ll sz = dfs(u, i);
            ans += sz * (sz - 1) / 2;
        }
        for (auto el: visited_now) {
            visited[el] = false;
        }
        visited_now.clear();
        cout << ans << endl;
    }
    return 0;
}