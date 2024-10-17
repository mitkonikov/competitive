#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int K = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans{ (int)1e9, (int)-1e9 };
        multiset<int> ms;
        for (int i = 0; i < K; i++) {
            pq.push(make_pair(nums[i][0], i));
            ans[0] = min(ans[0], nums[i][0]);
            ans[1] = max(ans[1], nums[i][0]);
            ms.insert(nums[i][0]);
        }
        vector<int> where(K, 0);
        auto eraseone = [&](int x) {
            auto it = ms.find(x);
            if (it != ms.end()) ms.erase(it);
        };
        auto updateans = [&]() {
            // update the ans
            int nl = *ms.begin();
            int nr = *prev(ms.end());
            if (nr - nl < ans[1] - ans[0]) {
                ans = { nl, nr };
            }
        };
        while (!pq.empty()) {
            auto [cost, id] = pq.top();
            pq.pop();
            int next = where[id] + 1;
            updateans();
            if (next >= nums[id].size()) continue;
            eraseone(cost);
            pq.push(make_pair(nums[id][next], id));
            ms.insert(nums[id][next]);
            where[id]++;
        }
        return ans;
    }
};