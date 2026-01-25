#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        map<int, int> frq_front, frq_back;
        for (int i = 0; i < nums.size(); i++) {
            frq_back[nums[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            frq_back[nums[i]]--;
            ans = (ans + ((long long)frq_front[nums[i] * 2] * frq_back[nums[i] * 2]) % MOD) % MOD;
            frq_front[nums[i]]++;
        }
        return ans;
    }
};