#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> parent;
vector<vector<int>> adj;
vector<ll> b, t;
vector<ll> c;
vector<priority_queue<int>> ms;
vector<vector<int>> to_put;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    adj.resize(N);
    parent.resize(N);
    b.resize(N);
    t.resize(N);
    c.resize(N);
    ms.resize(N);
    to_put.resize(N);
    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        adj[parent[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) cin >> b[i];
    for (int i = 0; i < N; i++) cin >> t[i];
    for (int i = N - 1; i >= 0; i--) {
        // merge small to large
        for (int j = 0; j < adj[i].size(); j++) {
            auto v = adj[i][j];
            if (ms[v].size() > ms[i].size()) {
                ms[v].swap(ms[i]);
            }
        }
        
        for (int j = 0; j < adj[i].size(); j++) {
            auto v = adj[i][j];
            while (!ms[v].empty()) {
                ms[i].push(ms[v].top());
                ms[v].pop();
            }
            for (const auto el: to_put[v]) {
                ms[i].push(el);
            }
            to_put[v].clear();
            ms[v] = priority_queue<int>();
        }
        if (b[i] != 0) ms[i].push(b[i]);
        
        // process the multiset
        while (!ms[i].empty() && ms[i].top() >= t[i]) {
            auto val = ms[i].top();
            ms[i].pop();
            ll take = (ll)(val / t[i]) * t[i];
            val -= take;
            c[i] += take;
            if (val > 0) to_put[i].push_back(val);
        }

        if (i) t[i-1] ^= c[i];
    }
    for (auto el: c) cout << el << " ";
    cout << endl;
    return 0;
}