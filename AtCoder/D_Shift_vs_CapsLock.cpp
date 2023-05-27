#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<ll>> dp(N, vector<ll>(2, INT_MAX));
    dp[0][0] = (S[0] == 'a' ? X : Y);
    dp[0][1] = Z + (S[0] == 'a' ? Y : X);
    for (int i = 1; i < N; i++) {
        bool state = S[i] == 'A';
        dp[i][0] = min({
            dp[i-1][0] + (state ? Y : X),
            dp[i-1][1] + (state ? X : Y) + Z,
            dp[i-1][1] + Z + (state ? Y : X) });
        dp[i][1] = min({
            dp[i-1][0] + Z + (state ? X : Y),
            dp[i-1][0] + (state ? Y : X) + Z,
            dp[i-1][1] + (state ? X : Y)
        });
    }
    cout << min(dp[N-1][0], dp[N-1][1]) << endl;
    return 0;
}