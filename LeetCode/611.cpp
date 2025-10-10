#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> fwt;

    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void add(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    int get(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        FenwickTree tree(2010);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < N; j++) {
                int large = nums[i] + nums[j];
                int small = nums[j] - nums[i];
                ans += tree.get(large - 1) - tree.get(small);
            }
            tree.add(nums[i]);
        }
        return ans;
    }
};