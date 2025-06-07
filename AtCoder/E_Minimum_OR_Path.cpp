#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    struct edge {
        int v, w;
        bool enabled = false;
    };
    vector<vector<edge>> adj(N);
    int MXW = 0;
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U--; V--;
        MXW = max(MXW, W);
        adj[U].push_back({ V, W });
        adj[V].push_back({ U, W });
    }
    int MSB = 0;
    for (int i = 0; i < 30; i++) {
        if ((1 << i) & MXW) MSB = i;
    }
    int ans = 0;
    for (int rep = 0; rep <= MSB; rep++) {
        for (int b1 = -1; b1 <= MSB - rep; b1++) {
            int all = (b1 >= 0 ? ((1LL << (b1 + 1)) - 1) : 0);
            for (int i = 0; i < N; i++) {
                for (auto& edge: adj[i]) {
                    edge.enabled = (edge.w & (ans | all)) == edge.w;
                }
            }

            queue<int> bfs;
            vector<bool> visited(N);
            visited[0] = true;
            bfs.push(0);
            while (!bfs.empty()) {
                auto top = bfs.front();
                bfs.pop();
                for (auto edge: adj[top]) {
                    if (edge.enabled && !visited[edge.v]) {
                        visited[edge.v] = true;
                        bfs.push(edge.v);
                    }
                }
            }
            
            if (visited[N-1]) {
                if (b1 >= 0) {
                    ans |= (1 << b1);
                } else {
                    cout << ans << endl;
                    return 0;
                }
                break;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}