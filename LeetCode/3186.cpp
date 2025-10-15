#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        vector<pair<int, long long>> vec;
        map<int, int> frq;
        const int N = power.size();
        for (int i = 0; i < N; i++) {
            frq[power[i]]++;
        }
        for (auto& [el, f] : frq) {
            vec.push_back({ el, (ll)el * f });
        }
        const int M = vec.size();
        vector<long long> dp(M), acc(M);
        long long ans = 0;
        for (int i = 0; i < M; i++) {
            dp[i] = vec[i].second;
            for (int j = 1; j <= 3; j++) {
                if (i - j >= 0 && vec[i].first > vec[i-j].first + 2) {
                    dp[i] = max(dp[i], vec[i].second + acc[i-j]);
                    dp[i] = max(dp[i], vec[i].second + dp[i-j]);
                }
            }
            acc[i] = dp[i];
            if (i) acc[i] = max(acc[i], acc[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};