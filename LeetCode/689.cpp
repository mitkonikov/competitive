#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        int N = nums.size();
        vector<ll> pref(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) pref[i] = nums[i];
            else pref[i] = pref[i-1] + nums[i];
        }
        vector<ll> sums(N);
        for (int i = 0; i < N - K + 1; i++) {
            sums[i] = pref[i + K - 1] - (i == 0 ? 0 : pref[i-1]);
        }
        vector<vector<ll>> best(N, vector<ll>(3, 0));
        vector<vector<int>> bestId(N, vector<int>(3, -1));
        for (int rep = 0; rep < 3; rep++) {
            for (int i = N - (rep+1) * K; i >= 0; i--) {
                bestId[i][rep] = i;
                best[i][rep] = sums[i] + (rep == 0 ? 0 : best[i+K][rep-1]);
                if (i+1 < N && bestId[i+1][rep] != -1 && 
                    best[i+1][rep] > best[i][rep]) {
                    best[i][rep] = best[i+1][rep];
                    bestId[i][rep] = bestId[i+1][rep];
                }
            }
        }
        vector<int> ans{ bestId[0][2] };
        for (int rep = 1; rep >= 0; rep--) {
            ans.push_back(bestId[ans.back()+K][rep]);
        }
        return ans;
    }
};