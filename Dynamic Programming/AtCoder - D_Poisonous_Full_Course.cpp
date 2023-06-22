#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline void umax(ll& a, ll b) {
    if (b > a) a = b;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> courses(N);
    for (int i = 0; i < N; i++) {
        cin >> courses[i].first >> courses[i].second;
    }
    vector<vector<ll>> dp(N, vector<ll>(2, 0));
    if (courses[0].first == 0) {
        umax(dp[0][0], courses[0].second);
    } else {
        umax(dp[0][1], courses[0].second);
    }
    for (int i = 1; i < N; i++) {
        umax(dp[i][0], dp[i-1][0]);
        umax(dp[i][1], dp[i-1][1]);
        if (courses[i].first == 0) {
            umax(dp[i][0], dp[i-1][0] + courses[i].second);
            umax(dp[i][0], dp[i-1][1] + courses[i].second);
        } else {
            umax(dp[i][1], dp[i-1][0] + courses[i].second);
        }
    }
    cout << max(dp[N-1][0], dp[N-1][1]) << endl;
    return 0;
}