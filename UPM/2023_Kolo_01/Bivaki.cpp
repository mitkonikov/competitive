#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
template<typename T>
struct MaxFlow {
public:
    int N;
    vector<vector<T>> adj;
    vector<vector<T>> capacity;
    T INF = numeric_limits<T>::max();
 
    struct Flow {
        T node;
        T flow;
    };
 
    MaxFlow(int N) {
        this->N = N;
        adj.resize(N, vector<T>());
        capacity.resize(N, vector<T>(N, 0));
    }
 
    void addEdge(int u, int v, T c) {
        capacity[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    T bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        queue<Flow> q;
        q.push({ source, INF });
        while (!q.empty()) {
            T currentNode = q.front().node;
            T flow = q.front().flow;
            q.pop();
            
            for (int nextNode: adj[currentNode]) {
                if (parent[nextNode] == -1 && capacity[currentNode][nextNode] > 0) {
                    parent[nextNode] = currentNode;
                    T new_flow = min(flow, capacity[currentNode][nextNode]);
                    if (nextNode == sink) return new_flow;
                    q.push({ nextNode, new_flow });
                    assert(new_flow != INF);
                }
            }
        }
 
        return 0;
    }
 
    T getMaxFlow(int source, int sink) {
        vector<int> parent(N);
        T flow = 0;
        T new_flow;
 
        while (new_flow = bfs(source, sink, parent)) {
            flow += new_flow;
            T current = sink;
            while (current != source) {
                int prev = parent[current];
                capacity[prev][current] -= new_flow;
                capacity[current][prev] += new_flow;
                current = prev;
            }
        }
 
        return flow;
    }
};
 
int main() {
    int N;
    cin >> N;
    N += 2;
    MaxFlow<ll> mf(2 * N);
    vector<ll> cap(N + 10);
    for (int i = 1; i <= N - 2; i++) {
        cin >> cap[i];
        mf.addEdge(2 * i, 2 * i + 1, cap[i]);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        mf.addEdge(2 * u + 1, 2 * v, 1e18);
        mf.addEdge(2 * v + 1, 2 * u, 1e18);
    }
    cout << mf.getMaxFlow(1, 2 * (N - 1)) << endl;
    return 0;
}