#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = { u, v };
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << N); mask++) {
        int del = 0;
        auto sign = [](int n) {
            return n > 0;
        };
        for (int e = 0; e < M; e++) {
            if (sign(mask & (1 << edges[e].first)) == sign(mask & (1 << edges[e].second))) {
                del++;
            }
        }
        ans = min(ans, del);
    }
    cout << ans << endl;
    return 0;
}