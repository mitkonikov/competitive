#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> pref_dp(N, 1), suff_dp(N, 1);
    for (int i = 1; i < N; i++) {
        pref_dp[i] = min(pref_dp[i-1], A[i] - 1) + 1;
    }
    for (int i = N - 2; i >= 0; i--) {
        suff_dp[i] = min(suff_dp[i+1], A[i] - 1) + 1;
    }
    int ans = 1;
    for (int i = 1; i < N - 1; i++) {
        int mn = min(pref_dp[i-1], suff_dp[i+1]);
        if (A[i] > mn) {
            ans = max(ans, mn + 1);
        }
    }
    cout << ans << endl;
    return 0;
}