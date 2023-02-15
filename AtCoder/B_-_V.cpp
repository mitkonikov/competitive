#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        // A[i], A[i+1]
        adj[A[i]].push_back(A[i] + 1);
    }
    vector<bool> visited(N + 1);
    vector<vector<int>> comps;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        comps.push_back({ i });
        int t = i;
        visited[t] = true;
        while (!adj[t].empty()) {
            t = adj[t][0];
            visited[t] = true;
            comps.back().push_back(t);
        }
    }
    for (int i = 0; i < comps.size(); i++) {
        reverse(comps[i].begin(), comps[i].end());
        for (auto el: comps[i]) {
            cout << el << " ";
        }
    }
    cout << endl;
    return 0;
}