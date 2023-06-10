#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> visited(N + 1);
    vector<int> parent(N + 1);
    int cur = 1;
    while (true) {
        visited[cur] = true;
        int k;
        cin >> k;
        vector<int> adj(k);
        vector<int> unvisited;
        for (int i = 0; i < k; i++) {
            cin >> adj[i];
            if (!visited[adj[i]]) {
                parent[adj[i]] = cur;
                unvisited.push_back(adj[i]);
                if (adj[i] == N) {
                    unvisited[0] = N;
                }
            }
        }
        if (unvisited.empty()) {
            cur = parent[cur];
        } else {
            cur = unvisited[0];
        }
        cout << cur << endl;
        if (cur == N) break;
    }
    string S;
    cin >> S;
    return 0;
}