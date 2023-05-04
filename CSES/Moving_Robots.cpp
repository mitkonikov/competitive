#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int N;
    cin >> N;
    vector<vector<double>> dp2(8, vector<double>(8, 1));
    for (int sx = 0; sx < 8; sx++) {
        for (int sy = 0; sy < 8; sy++) {
            // for each starting square
            vector<vector<double>> dp(8, vector<double>(8, 0));
            dp[sx][sy] = 1;
            for (int i = 0; i < N; i++) {
                vector<vector<double>> new_dp(8, vector<double>(8, 0));
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (dp[x][y] == 0) continue;
                        int valid = 0;
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                                valid++;
                            }
                        }
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                                new_dp[nx][ny] += dp[x][y] / valid;
                            }
                        }
                    }
                }
                dp.swap(new_dp);
            }

            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    dp2[x][y] *= (1 - dp[x][y]);
                }
            }
        }
    }
    
    double ans = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            ans += dp2[x][y];
        }
        cout << endl;
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}