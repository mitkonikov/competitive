#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    const int mxs = 10010;
    vector<vector<int>> dp(n, vector<int>(mxs, 0));
    vector<pair<int, int>> cards(n);
    for (int i = 0; i < n; i++) cin >> cards[i].first >> cards[i].second;
    dp[0][cards[0].first] = 1;
    dp[0][cards[0].second] = -1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < mxs; j++) {
            if (dp[i][j] != 0) {
                dp[i+1][j+cards[i+1].first] = 1;
                dp[i+1][j+cards[i+1].second] = -1;
            }
        }
    }
    if (dp[n-1][s] == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        string ans = "";
        int sum = s;
        for (int i = n - 1; i >= 0; i--) {
            ans += (dp[i][sum] == -1 ? "T" : "H");
            sum -= (dp[i][sum] == -1 ? cards[i].second : cards[i].first);
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    cout << flush;
    return 0;
}