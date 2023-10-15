#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N), radj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<double> dp(N, 0);
    vector<vector<double>> poss(N);
    dp[N-1] = 1;
    for (int i = N - 1; i >= 0; i--) {
        sort(poss[i].rbegin(), poss[i].rend());
        double prob = (double) 1 / adj[i].size();
        for (int j = 0; j < poss[i].size(); j++) {
            dp[i] += prob * poss[i][j];
            if (adj[i].size() - j * 2 <= 0) { break; }
            prob = ((double)1 - prob) / (adj[i].size() - j * 2);
        }
        for (auto v: radj[i]) {
            poss[v].push_back(dp[i]);
        }
    }
    cout << fixed << setprecision(16) << dp[0] << endl;
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