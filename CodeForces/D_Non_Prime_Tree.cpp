#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> possible;
vector<int> ans;
int N;
int lp, rp;

int dfs(int u, int p, int c) {
    if (c == 0) {
        ans[u] = possible[lp];
        lp++;
    } else {
        ans[u] = possible[rp];
        rp--;
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, c^1);
    }
}

void testCase() {
    cin >> N;
    adj.clear();
    adj.resize(N);
    possible.clear();
    ans.clear();
    ans.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 2; i <= 2 * N; i += 2) {
        possible.push_back(i);
    }
    lp = 0;
    rp = possible.size() - 1;
    for (int i = 0; i < N; i++) {
        if (adj[i].size() == 1) {
            dfs(adj[i][0], i, 0);
            ans[i] = 1;
            break;
        }
    }
    for (auto el: ans) {
        cout << el << " ";
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