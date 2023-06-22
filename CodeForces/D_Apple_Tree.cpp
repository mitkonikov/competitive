#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> leafs;

int dfs(int u, int p) {
    if (p != -1 && adj[u].size() == 1) {
        return leafs[u] = 1;
    }

    int sum = 0;
    for (auto v: adj[u]) {
        if (v == p) continue;
        sum += dfs(v, u);
    }

    return leafs[u] = sum;
}

void testCase() {
    int N;
    cin >> N;
    adj.clear();
    adj.resize(N);
    leafs.clear();
    leafs.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cout << (ll)leafs[u] * leafs[v] << endl;
    }
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