#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        adj[U].push_back(V);
    }
    // dp[u][bob/alice][k]
    // alice = 0, bob = 1
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(2 * K + 1, -1)));
    auto dfs = [&](auto&& self, int u, int turn, int k) -> int {
        if (dp[u][turn][k] != -1) return dp[u][turn][k];
        if (k == 0) {
            dp[u][turn][k] = (int)(turn == (int)(S[u] - 'A'));
            return dp[u][turn][k];
        }
        for (auto& v : adj[u]) {
            int wins_opposite = self(self, v, turn ^ 1, k - 1);
            if (!wins_opposite) {
                dp[u][turn][k] = 1;
                return 1;
            }
        }
        dp[u][turn][k] = 0;
        return 0;
    };
    int win = dfs(dfs, 0, 0, K * 2);
    cout << (win ? "Alice" : "Bob") << endl;
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