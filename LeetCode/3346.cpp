#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        int l = 0;
        int r = 0;
        map<int, int> frq;
        multiset<int> fms;
        auto update = [&](int id, int diff) {
            auto mit = fms.find(frq[nums[id]]);
            if (mit != fms.end()) fms.erase(mit);
            frq[nums[id]] += diff;
            auto it = frq.find(nums[id]);
            if (it->second == 0) frq.erase(it);
            else fms.insert(frq[nums[id]]);
        };
        for (int C = 0; C <= nums.back(); C++) {
            while (r < N && nums[r] - C <= k) {
                update(r, 1);
                r++;
            }

            while (l < N && C - nums[l] > k) {
                update(l, -1);
                l++;
            }

            int best = 0;
            int all = r - l;
            auto it = frq.find(C);
            if (it != frq.end()) {
                best = it->second;
                all -= it->second;
            }
            best += min(numOperations, all);
            ans = max(ans, best);
        }
        return ans;
    }
};