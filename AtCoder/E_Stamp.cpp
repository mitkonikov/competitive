#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    for (int i = 0; i < N - M + 1; i++) {
        int l = 0;
        for (int j = 0; j < M; j++) {
            if (S[i+j] == T[j]) l++;
            else break;
        }
        
        if (i == 0 || dp[i-1][0]) for (int k = 0; k < l; k++) dp[i+k][0] = max(dp[i+k][0], k+1);
        if ((i == 0 || dp[i-1][0] || dp[i-1][1]) && l == M) {
            dp[i][1] = 1;
        }

        for (int j = 1; j < M; j++) {
            int last = i + j - M;
            if (last >= 0 && (dp[last][1] || dp[i+j-1][0] == M)) {
                for (int k = j; k < M; k++) {
                    if (S[i+k] == T[k]) {
                        dp[i+k][0] = max(dp[i+k][0], k+1);
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout << ((dp[N-1][0] == M || dp[N-M][1]) ? "Yes" : "No") << endl;
    return 0;
}