#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<map<int, int>> adj(N);
    for (int i = 0; i < N; i++) {
        int u = A[i] - 1;
        adj[u][i]++;
        adj[i][u]++;
    }

    vector<bool> visited(N);
    int comp = 0;
    int free = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        queue<int> bfs;
        bfs.push(i);
        bool free_comp = 0;
        while (!bfs.empty()) {
            auto t = bfs.front();
            bfs.pop();
            for (auto el: adj[t]) {
                if (el.second == 2) {
                    if (adj[t].size() == 1) {
                        free_comp = 1;
                    }
                }
                if (visited[el.first]) continue;
                bfs.push(el.first);
                visited[el.first] = 1;
            }
        }
        comp++;
        free += free_comp;
    }

    cout << comp - free + (free > 0) << " " << comp << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}