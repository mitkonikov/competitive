#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int N = questions.size();
        vector<ll> dp(N + 1);
        auto update = [](ll& a, ll b) {
            if (b > a) a = b;
        };
        for (int i = 0; i < N; i++) {
            const int points = questions[i][0];
            const int power = questions[i][1];
            update(dp[min(N, i + power + 1)], dp[i] + points);
            update(dp[i + 1], dp[i]);
        }
        return dp[N];
    }
};