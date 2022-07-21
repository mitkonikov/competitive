#include <bits/stdc++.h>

using namespace std;

class MaxFlow {
public:
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> capacity; // stores the residual flow
    vector<vector<int>> flows; // stores the flow
    vector<vector<bool>> direction; // stores the edges direction

    struct Flow {
        int node;
        int flow;
    };

    MaxFlow(int n) {
        this->n = n;
        this->adj.resize(n, vector<int>());
        this->capacity.resize(n, vector<int>(n, 0));
        this->direction.resize(n, vector<bool>(n, false));
        this->flows.resize(n, vector<int>(n, 0));
    }

    int bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2; // NULL value
        queue<Flow> q;
        q.push({ source, INT_MAX });

        while(!q.empty()) {
            int currentNode = q.front().node;
            int flow = q.front().flow;
            q.pop();

            for (int nextNode: adj[currentNode]) {
                if (parent[nextNode] == -1 && capacity[currentNode][nextNode] > 0) {
                    parent[nextNode] = currentNode;
                    int new_flow = min(flow, capacity[currentNode][nextNode]);
                    if (nextNode == sink) return new_flow;
                    q.push({ nextNode, new_flow });
                    assert(new_flow != INT_MAX);
                }
            }
        }

        return 0;
    }

    int getMaxFlow(int source, int sink) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(source, sink, parent)) {
            flow += new_flow;
            int current = sink;
            while (current != source) {
                int prev = parent[current];
                flows[prev][current] += new_flow;
                flows[current][prev] -= new_flow;
                capacity[prev][current] -= new_flow;
                capacity[current][prev] += new_flow;
                current = prev; // go back
            }
        }

        return flow;
    };

    map<pair<int, int>, int> getEdges() {
        map<pair<int, int>, int> result; // edge (u, v) mapped to flow
        for (int i = 0; i < (int)adj.size(); i++) {
            for (int j = 0; j < (int)adj[i].size(); j++) {
                int nextNode = adj[i][j];
                if (flows[i][nextNode] > 0 && direction[i][nextNode]) {
                    result[{ i, nextNode }] = flows[i][nextNode];
                }
            }
        }

        return result;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int source, sink;
    cin >> source >> sink;

    MaxFlow mf(n);

    for (int i = 0; i < m; i++) {
        int s, e, c; cin >> s >> e >> c;
        mf.direction[s][e] = true;
        mf.adj[s].push_back(e);
        mf.adj[e].push_back(s);
        mf.capacity[s][e] += c;
    }

    int flow = mf.getMaxFlow(source, sink);
    auto edges = mf.getEdges();

    cout << n << " " << flow << " " << (int)edges.size() << endl;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        cout << it->first.first << " " << it->first.second << " " << it->second << endl;
    }
    
    return 0;
}