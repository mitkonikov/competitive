#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    const int MX = 6 * N + 100;
    vector<double> dp(MX);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        vector<double> new_dp(MX);
        for (int j = 0; j < dp.size(); j++) {
            for (int k = 1; k <= 6; k++) {
                new_dp[j + k] += dp[j] / 6;
            }
        }
        dp.swap(new_dp);
    }
    double ans = 0;
    for (int i = A; i <= B; i++) {
        ans += dp[i];
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}