#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;

    vector<ll> cost(N);
    for (int i = 0; i < N; i++) cin >> cost[i];

    for (int i = 0; i < K; i++) {
        int id;
        cin >> id;
        id--;
        cost[id] = 0;
    }

    vector<vector<int>> edges(N);
    vector<vector<int>> rev_edges(N);

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        edges[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> edges[i][j];
            edges[i][j]--;
            rev_edges[edges[i][j]].push_back(i);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({ cost[i], i });
    }
    
    while (!pq.empty()) {
        auto [c, i] = pq.top();
        pq.pop();

        if (cost[i] < c) continue;
        if (edges[i].size() == 0) continue;
        
        ll newCost = 0;
        for (auto v: edges[i]) {
            newCost += cost[v];
        }

        if (newCost < cost[i]) {
            cost[i] = newCost;
            for (auto v: rev_edges[i]) {
                cost[v] -= (cost[i] - newCost);
                pq.push({ cost[v], v });
            }
        }
    }

    for (auto el: cost) cout << el << " ";
    cout << endl;
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