#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    adj.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (S[i] < S[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(N);
    vector<int> visited(N);
    for (int i = 0; i < N; i++) {
        if (adj[i].empty() || visited[i]) continue;
        queue<int> bfs;
        bfs.push(i);
        color[i] = 1;
        visited[i] = true;
        while (!bfs.empty()) {
            auto t = bfs.front();
            bfs.pop();
            for (auto v: adj[t]) {
                if (!visited[v]) {
                    visited[v] = true;
                    bfs.push(v);
                    color[v] = color[t] ^ 1;
                } else {
                    if (color[v] == color[t]) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    for (auto bit: color) cout << bit;
    cout << endl;
    return 0;
}