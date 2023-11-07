#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<map<int, int>> dp(11);
    for (int i = 0; i < N; i++) {
        int sum_all_me = 0;
        for (int j = 0; j < A[i].size(); j++) sum_all_me += A[i][j] - '0';
        dp[A[i].size()][sum_all_me]++;
    }
    
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int sum_all_me = 0;
        for (int j = 0; j < A[i].size(); j++) sum_all_me += A[i][j] - '0';
        
        int sum_left = 0;
        for (int left = 1; left < A[i].size(); left++) {
            sum_left += A[i][A[i].size() - left] - '0';
            int target_sum = sum_left - (sum_all_me - sum_left);
            int target_size = left - (A[i].size() - left);
            if (target_sum < 0 || target_size > 5 || target_size <= 0) continue;
            ans += dp[target_size][target_sum];
        }

        int sum_right = 0;
        for (int right = 1; right < A[i].size(); right++) {
            sum_right += A[i][right - 1] - '0';
            int target_sum = sum_right - (sum_all_me - sum_right);
            int target_size = right - (A[i].size() - right);
            if (target_sum < 0 || target_size > 5 || target_size <= 0) continue;
            ans += dp[target_size][target_sum];
        }

        ans += dp[A[i].size()][sum_all_me];
    }
    cout << ans << endl;
    return 0;
}