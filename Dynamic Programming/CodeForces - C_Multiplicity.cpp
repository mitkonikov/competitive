#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(2e6);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> changes;
        for (int j = 1; j <= sqrt(a[i]); j++) {
            if (a[i] % j == 0) {
                if (j * j != a[i]) {
                    changes.push_back({ a[i] / j, dp[a[i] / j - 1] });
                }

                changes.push_back({ j, dp[j-1] });
            }
        }

        for (auto& change: changes) {
            dp[change.first] = (dp[change.first] + change.second) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i < dp.size(); i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}