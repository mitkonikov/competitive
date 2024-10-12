#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MX = 510;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        sum += A[i].second;
    }
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    auto update = [](int& a, int b) {
        if (a > b) a = b;
    };
    // dp[team1][team2]
    vector<vector<int>> dp(MX, vector<int>(MX, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        vector<vector<int>> new_dp(MX, vector<int>(MX, 1e9));
        auto [x, y] = A[i];
        for (int a = 0; a < MX; a++) {
            for (int b = 0; b < MX; b++) {
                if (x == 1) {
                    if (a + y < MX) update(new_dp[a + y][b], dp[a][b]);
                    if (b + y < MX) update(new_dp[a][b + y], dp[a][b] + 1);
                    update(new_dp[a][b], dp[a][b] + 1);
                } else if (x == 2) {
                    if (a + y < MX) update(new_dp[a + y][b], dp[a][b] + 1);
                    if (b + y < MX) update(new_dp[a][b + y], dp[a][b]);
                    update(new_dp[a][b], dp[a][b] + 1);
                } else if (x == 3) {
                    if (a + y < MX) update(new_dp[a + y][b], dp[a][b] + 1);
                    if (b + y < MX) update(new_dp[a][b + y], dp[a][b] + 1);
                    update(new_dp[a][b], dp[a][b]);
                }
            }
        }
        swap(dp, new_dp);
    }
    int ans = dp[sum / 3][sum / 3];
    if (ans >= 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}