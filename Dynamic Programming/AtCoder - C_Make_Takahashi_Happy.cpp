#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<vector<set<int>>>> dp(N, vector<vector<set<int>>>(M));
    dp[0][0].push_back({ A[0][0] });
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) continue;
            if (j - 1 >= 0) {
                for (auto s: dp[i][j-1]) {
                    if (s.count(A[i][j])) continue;
                    dp[i][j].push_back(s);
                    dp[i][j].back().insert(A[i][j]);
                }
            }
            if (i - 1 >= 0) {
                for (auto s: dp[i-1][j]) {
                    if (s.count(A[i][j])) continue;
                    dp[i][j].push_back(s);
                    dp[i][j].back().insert(A[i][j]);
                }
            }
        }
    }
    cout << dp[N-1][M-1].size() << endl;
    return 0;
}