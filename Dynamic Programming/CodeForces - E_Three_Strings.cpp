#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline void update(int& a, int b) {
    if (b < a) a = b;
}

void testCase() {
    string A, B, C;
    cin >> A >> B >> C;
    int N = A.size();
    int M = B.size();
    A = "@" + A;
    B = "@" + B;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 && j == 0) continue;
            if (i) update(dp[i][j], dp[i-1][j] + 1);
            if (j) update(dp[i][j], dp[i][j-1] + 1);
            if (i && A[i] == C[i + j - 1]) {
                update(dp[i][j], dp[i-1][j]);
            }
            if (j && B[j] == C[i + j - 1]) {
                update(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[N][M] << endl;
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