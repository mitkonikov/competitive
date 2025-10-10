#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int N = nums.size();
        vector<pair<int, int>> intervals;
        for (int i = 0; i < N; i++) {
            if (nums[i] == key) {
                intervals.push_back(make_pair(max(0, i - k), min(N-1, i + k)));
            }
        }
        vector<pair<int, int>> merged{ intervals[0] };
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first <= merged.back().second) {
                merged.back().second = max(merged.back().second, intervals[i].second);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        vector<int> ans;
        for (auto& [l, r]: merged) {
            for (int i = l; i <= r; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};