#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
stack<int> st;
vector<bool> inside;
vector<bool> visited;

void dfs(int u) {
    if (inside[u]) {
        vector<int> ans;
        while (!st.empty() && st.top() != u) {
            ans.push_back(st.top());
            st.pop();
        }
        ans.push_back(u);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto u: ans) {
            cout << u + 1 << " ";
        }
        cout << endl;
        exit(0);
    }

    inside[u] = true;
    visited[u] = true;
    st.push(u);

    for (auto v: adj[u]) {
        dfs(v);
    }

    inside[u] = false;
    st.pop();
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    inside.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        int u;
        cin >> u;
        u--;
        adj[i].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        dfs(i);
    }
    return 0;
}