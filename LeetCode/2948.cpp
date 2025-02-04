#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int N = nums.size();
        struct I {
            int x, i, c;
        };
        vector<I> vec(N);
        for (int i = 0; i < N; i++) vec[i] = { nums[i], i, -1 };
        sort(vec.begin(), vec.end(), [](I& a, I& b) {
            if (a.x == b.x) return a.i < b.i;
            return a.x < b.x;
        });
        int comp = 0;
        vec[0].c = 0;
        for (int i = 1; i < N; i++) {
            if (vec[i].x - vec[i-1].x > limit) {
                comp++;
            }
            vec[i].c = comp;
        }
        vector<vector<I>> comps(comp + 1);
        for (int i = 0; i < N; i++) {
            comps[vec[i].c].push_back(vec[i]);
        }
        vector<int> ans(N);
        for (int i = 0; i < comps.size(); i++) {
            sort(comps[i].begin(), comps[i].end(), [](I& a, I& b) {
                if (a.x == b.x) return a.i < b.i;
                return a.x < b.x;
            });
            vector<int> ids;
            for (int j = 0; j < comps[i].size(); j++) {
                ids.push_back(comps[i][j].i);
            }
            sort(ids.begin(), ids.end());
            for (int j = 0; j < ids.size(); j++) {
                ans[ids[j]] = comps[i][j].x;
            }
        }
        return ans;
    }
};