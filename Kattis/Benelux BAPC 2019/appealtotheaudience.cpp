#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> values;

struct Edge {
    int depth = 0;
    int node = 0;

    bool operator<(const Edge &edge) {
        return (this->depth < edge.depth);
    }
};

struct Node {
    int maxDepth = 0;
    int assign = -1;
    vector<Edge> edges;
};

vector<Node> nodes;

int depthDFS(int node) {
    int currentMaxDepth = 0;
    for (auto &edge: nodes[node].edges) {
        int edgeDepth = depthDFS(edge.node);
        currentMaxDepth = max(currentMaxDepth, edgeDepth);
        edge.depth = edgeDepth;
    }

    nodes[node].maxDepth = currentMaxDepth + 1;
    return nodes[node].maxDepth;
}

ll BFS() {
    ll result = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    int pointer = 0;
    for (Edge edge: nodes[0].edges) {
        pq.push({ nodes[edge.node].maxDepth, edge.node });
    }

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if (nodes[top.second].assign == -1) {
            nodes[top.second].assign = values[pointer++];
        }
        
        result += nodes[top.second].assign;

        if (nodes[top.second].edges.size() == 0) continue;
        sort(nodes[top.second].edges.rbegin(), nodes[top.second].edges.rend());
        int chosen = nodes[top.second].edges[0].node;
        nodes[chosen].assign = nodes[top.second].assign;
        pq.push({ nodes[chosen].maxDepth, chosen });

        for (int i = 1; i < nodes[top.second].edges.size(); i++) {
            Edge nextEdge = nodes[top.second].edges[i];
            pq.push({ nodes[nextEdge.node].maxDepth, nextEdge.node });
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    values.resize(k);
    nodes.resize(n);

    for (int i = 0; i < k; i++) {
        cin >> values[i];
    }

    sort(values.rbegin(), values.rend());

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;

        nodes[parent].edges.push_back({ 0, i });
    }

    depthDFS(0);
    cout << BFS() << endl;

    return 0;
}