#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> frq;
        for (int i = 0; i < nums.size(); i++) {
            frq[nums[i]]++;
        }
        int ans = 0;
        for (auto it = frq.begin(); it != frq.end(); it++) {
            auto nxt = next(it);
            if (nxt != frq.end() && nxt->first == it->first + 1) {
                ans = max(ans, it->second + nxt->second);
            }
        }
        return ans;
    }
};