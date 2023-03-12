#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int id = 1;
int loops = 0, not_loops = 0;

bool dfs(int u, int p) {
    visited[u] = id;
    for (auto v: adj[u]) {
        if (v == p) continue;
        if (visited[v] == id) {
            return true;
        }
        if (visited[v]) {
            return true;
        }
        if (dfs(v, u)) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(2 * N);
    visited.resize(2 * N);
    for (int i = 0; i < M; i++) {
        int a, b;
        char ca, cb;
        cin >> a >> ca >> b >> cb;
        int CA = (ca == 'R' ? 0 : 1);
        int CB = (cb == 'R' ? 0 : 1);
        a--; b--;
        adj[2 * a + CA].push_back(2 * b + CB);
        adj[2 * b + CB].push_back(2 * a + CA);
    }
    for (int i = 0; i < N * 2; i += 2) {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }
    for (int i = 0; i < N * 2; i++) {
        if (visited[i] > 0) continue;
        if (dfs(i, -1)) loops++;
        else not_loops++;
        id++;
    }
    cout << loops << " " << not_loops << endl;
    return 0;
}