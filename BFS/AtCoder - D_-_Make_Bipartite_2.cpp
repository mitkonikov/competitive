#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(N, -1);
    vector<vector<int>> count;
    vector<int> comp(N, -1);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (color[i] != -1) continue; 
        queue<int> bfs;
        bfs.push(i);
        color[i] = 0;
        count.push_back({ 0, 0 });
        count.back()[color[i]]++;
        comp[i] = count.size() - 1;
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            comp[top] = count.size() - 1;
            for (auto v: adj[top]) {
                if (color[v] == -1) {
                    color[v] = color[top] ^ 1;
                    count.back()[color[v]]++;
                    bfs.push(v);
                } else {
                    if (color[v] != color[top] ^ 1) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int cur_ans = N;
        cur_ans -= adj[i].size();
        cur_ans -= count[comp[i]][color[i]];
        ans += cur_ans;
    }
    cout << ans / 2 << endl;
    return 0;
}