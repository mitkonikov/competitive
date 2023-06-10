#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int R, G, B;
    cin >> R >> G >> B;
    vector<vector<vector<ll>>> dp(R + 1, vector<vector<ll>>(G + 1, vector<ll>(B + 1)));
    vector<vector<int>> A(3);
    A[0].resize(R);
    A[1].resize(G);
    A[2].resize(B);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cin >> A[i][j];
        }
        sort(A[i].rbegin(), A[i].rend());
    }
    dp[0][0][0] = 0;
    ll ans = 0;
    for (int r = 0; r <= R; r++) {
        for (int g = 0; g <= G; g++) {
            for (int b = 0; b <= B; b++) {
                vector<int> i{r, g, b};
                for (int t1 = 0; t1 < 3; t1++) {
                    for (int t2 = 0; t2 < 3; t2++) {
                        if (t1 != t2 && i[t1] && i[t2]) {
                            dp[r][g][b] = max(dp[r][g][b], dp[r-(t1==0)-(t2==0)][g-(t1==1)-(t2==1)][b-(t1==2)-(t2==2)] + (ll)A[t1][i[t1]-1] * A[t2][i[t2]-1]);
                            ans = max(ans, dp[r][g][b]);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}