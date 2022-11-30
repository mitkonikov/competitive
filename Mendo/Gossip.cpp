#include <bits/stdc++.h>
#define ll long long

using namespace std;

void extend(set<int>& a, const set<int>& b) {
    for (auto el: b) a.insert(el);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<set<int>> ans(N);
    for (int i = 0; i < N; i++) ans[i].insert(i);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        extend(ans[u], ans[v]);
        extend(ans[v], ans[u]);
    }
    int mx = INT_MIN;
    for (int i = 0; i < N; i++) {
        mx = max(mx, (int)ans[i].size());
    }
    cout << mx - 1 << endl;
    return 0;
}