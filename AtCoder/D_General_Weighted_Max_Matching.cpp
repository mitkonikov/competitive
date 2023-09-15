#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct edge {
    int u, v, w;
};

vector<edge> edges;
vector<bool> visited;

ll dfs(int e, ll cost = 0) {
    ll ans = cost;
    for (int j = e; j < edges.size(); j++) {
        auto [u, v, w] = edges[j];
        if (!visited[u] && !visited[v]) {
            visited[u] = true;
            visited[v] = true;
            ans = max(ans, dfs(j + 1, cost + w));
            visited[u] = false;
            visited[v] = false;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    visited.resize(N);
    vector<vector<int>> mat(N, vector<int>(N, 0));
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> mat[i][j];
            edges.push_back({ i, j, mat[i][j] });
        }
    }
    sort(edges.begin(), edges.end(), [&](edge& a, edge& b) {
        return a.v > b.v;
    });
    cout << dfs(0) << endl;
    return 0;
}