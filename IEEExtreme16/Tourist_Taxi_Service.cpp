#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct edge {
    int u, v, cost;
};

struct state {
    ll cost;
    int vertex;
    set<int> visited_edges;

    bool operator>(const state& s) const {
        return (cost > s.cost);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--; v--;
        edges[i] = { u, v, cost };
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
    }

    // vector<int> -> cost
    vector<vector<state>> cost(n);
    vector<ll> ans(n, LLONG_MAX);

    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({ 0, 0, {} });
    cost[0].push_back({ 0, 0, {} });

    auto print = [&]() {
        for (int i = 0; i < cost.size(); i++) {
            cout << "node :" << i << endl;
            for (int j = 0; j < cost[i].size(); j++) {
                cout << "cost: " << cost[i][j].cost << endl;
                for (auto el : cost[i][j].visited_edges) {
                    cout << el << " ";
                } cout << endl;
            }
        }
    };

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq1;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        for (auto edge: adj[top.vertex]) {
            
            for (auto s: cost[top.vertex]) {
                if (s.visited_edges.size() >= 5) {
                    ans[s.vertex] = min(ans[s.vertex], s.cost);
                    pq1.push({ ans[s.vertex], s.vertex });
                    continue;
                }

                set<int> new_state = s.visited_edges;
                new_state.insert(edge.second);
                bool skip = false;
                for (auto n_states: cost[edge.first]) {
                    if (n_states.visited_edges == new_state) {
                        skip = true;
                    }
                }

                if (skip) continue;
                if (new_state.size() > s.visited_edges.size()) {
                    state to_push = state{
                        s.cost + edges[edge.second].cost,
                        edge.first,
                        new_state
                    };

                    cost[edge.first].push_back(to_push);
                    pq.push(to_push);
                }
            }

        }
    }

    while (!pq1.empty()) {
        auto top = pq1.top();
        pq1.pop();

        for (auto edge: adj[top.second]) {
            if (ans[edge.first] > ans[top.second] + edges[edge.second].cost) {
                ans[edge.first] = ans[top.second] + edges[edge.second].cost;
                pq1.push({ ans[edge.first], edge.first });
            }
        }
    }

    for (auto el: ans) {
        cout << el << endl;
    }

    return 0;
}