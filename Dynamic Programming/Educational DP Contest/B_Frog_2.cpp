// 
// There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h 
// There is a frog who is initially on Stone 1. He will repeat the following action
// some number of times to reach Stone N:
//    - If the frog is currently on Stone i, jump to one of the following: Stone i+1, i+2 ... i+K. 
//      Here, a cost of | h[i] - h[j] | is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.
// 
//   Time Complexity: O(NK)
// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    cin >> n >> K;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int cur_ans = dp[i-1] + abs(heights[i] - heights[i-1]);
        for (int k = 2; k <= K; k++) {
            if (i - k >= 0) {
                cur_ans = min(cur_ans, dp[i-k] + abs(heights[i] - heights[i-k]));
            }
        }
        dp[i] = cur_ans;
    }

    cout << dp[n-1] << endl;
    return 0;
}