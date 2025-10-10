#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        const int N = nums.size();
        map<int, int> frq;
        for (int i = x; i < N; i++) {
            frq[nums[i]]++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < N; i++) {
            auto lb = frq.lower_bound(nums[i]);
            if (lb != frq.end()) {
                ans = min(ans, abs(nums[i] - lb->first));
            }

            if (lb != frq.begin()) {
                lb = prev(lb);
                ans = min(ans, abs(nums[i] - lb->first));
            }

            if (i - x >= 0) {
                frq[nums[i-x]]++;
            }

            if (i + x < N) {
                frq[nums[i+x]]--;
                if (frq[nums[i+x]] == 0) {
                    frq.erase(nums[i+x]);
                }
            }
        }
        return ans;
    }
};