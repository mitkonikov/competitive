#include <bits/stdc++.h>
#define ll long long

using namespace std;

void extend(vector<int>& a, const vector<int>& b, vector<vector<int>>& where, int id) {
    a.reserve((int)a.size() + b.size());
    int size = b.size();
    for (int i = 0; i < size; i++) {
        a.push_back(b[i]);
        where[b[i]].push_back(id);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> sets(N + 2);
    vector<vector<int>> where(M + 10);
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        vector<int> s(K);
        bool c1 = false, cm = false;
        for (int j = 0; j < K; j++) {
            cin >> s[j];
            if (s[j] == 1) c1 = true;
            if (s[j] == M) cm = true;
        }
        if (c1 && cm) {
            ans = 0;
        }
        if (c1) extend(sets[N], s, where, N);
        else if (cm) extend(sets[N+1], s, where, N + 1);
        else extend(sets[i], s, where, i);
    }
    if (ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (sets[N].empty() || sets[N+1].empty()) {
        cout << -1 << endl;
        return 0;
    }
    queue<int> bfs;
    vector<int> dist(M + 10, INT_MAX);
    vector<bool> visited_set(N + 10);
    dist[1] = 0;
    bfs.push(1);
    while (!bfs.empty()) {
        auto t = bfs.front();
        bfs.pop();
        
        for (auto s: where[t]) {
            if (visited_set[s]) continue;
            visited_set[s] = true;
            for (auto el: sets[s]) {
                if (dist[el] > dist[t] + 1) {
                    dist[el] = dist[t] + 1;
                    bfs.push(el);
                }
            }
        }
    }
    if (dist[M] != INT_MAX) ans = min(ans, dist[M] - 1);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}