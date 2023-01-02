#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(2);
    for (int i = 0; i < 2; i++) cin >> S[i];
    vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(N, vector<bool>(3, 0)));
    dp[0][0][2] = 1;
    if (S[1][0] == 'S') {
        dp[1][0][1] = 1;    
    } else {
        dp[1][0][2] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                int dec0 = (S[0][i] == '.' ? 0 : 1);
                int dec1 = (S[1][i] == '.' ? 0 : 1);
                bool can = dp[j][i-1][k];
                if (can && k-dec0>=0) {
                    dp[0][i][k-dec0] = 1;
                }
                if (can && k-dec1>=0) {
                    dp[1][i][k-dec1] = 1;
                }
            }
        }
    }
    cout << ((dp[1][N-1][0] || dp[1][N-1][1] || dp[1][N-1][2]) ? "YES" : "NO") << endl;
    return 0;
}