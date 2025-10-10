#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> order(N);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });
        order.resize(k);
        sort(order.begin(), order.end());
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = nums[order[i]];
        }
        return ans;
    }
};