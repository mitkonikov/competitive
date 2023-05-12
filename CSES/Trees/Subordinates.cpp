#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> parent;
vector<vector<int>> adj;
vector<int> ans;

int dfs(int u) {
    ans[u] = 0;
    for (auto v: adj[u]) {
        ans[u] += dfs(v);
    }
    return ans[u] + 1;
}

int main() {
    int N;
    cin >> N;
    parent.resize(N);
    adj.resize(N);
    ans.resize(N);
    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        adj[parent[i]].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}