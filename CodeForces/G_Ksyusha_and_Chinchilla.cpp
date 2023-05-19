#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> subsize, ans;
bool ok = 1;

void dfs(int u, int p = -1) {
    for (auto [v, e]: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (subsize[v] == 3) {
            subsize[v] -= 3;
            ans.push_back(e);
        }
        subsize[u] += subsize[v];
    }
    if (subsize[u] > 3) ok = false;
    if (p == -1) {
        ok &= (subsize[u] == 3 || subsize[u] == 0);
    }
}

void testCase() {
    int N;
    cin >> N;
    adj.clear();
    adj.resize(N + 10);
    subsize.clear();
    subsize.resize(N + 10, 1);
    ans.clear();
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back({ v, i + 1 });
        adj[v].push_back({ u, i + 1 });
    }
    ok = true;
    dfs(0);
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto edge: ans) {
        cout << edge << " ";
    }
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