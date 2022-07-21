#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define INF 1e9 + 1000

using namespace std;

vector<vector<int>> adj;
vector<int> tel;

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    tel.reserve(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u == -1) {
            tel.push_back(v);
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<ll> dist1(n, INF), distN(n, INF);
    dist1[0] = 0;
    distN[n-1] = 0;
    
    auto bfs = [&](int s, vector<ll> &d) {
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto v: adj[top]) {
                if (v != top && d[v] == INF) {
                    d[v] = d[top] + 1;
                    q.push(v);
                }
            }
        }
    };

    bfs(0, dist1);
    bfs(n-1, distN);

    ll minN = INF;
    ll min1 = INF;

    for (int i = 0; i < tel.size(); i++) {
        minN = min(minN, distN[tel[i]]);
        min1 = min(min1, dist1[tel[i]]);
    }

    vector<ll> ans(n, dist1[n-1]);
    for (int i = 0; i < n; i++) {
        ll a = dist1[i] + 1 + minN;
        ll b = distN[i] + 1 + min1;
        ans[i] = min({ ans[i], a, b });
        ans[i] = min(ans[i], minN + min1 + 2);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == INF) cout << -1 << " ";
        else cout << ans[i] << " ";
    } cout << endl;
    
    cout << flush;
    return 0;
}