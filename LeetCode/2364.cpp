#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i == nums[j] - nums[i]
        // j - nums[j] == - nums[i] + i
        const ll N = nums.size();
        map<ll, ll> dp;
        ll ans = N * (N - 1) / 2;
        for (int i = 0; i < N; i++) {
            ans -= dp[-nums[i] + i];
            dp[i - nums[i]]++;
        }
        return ans;
    }
};