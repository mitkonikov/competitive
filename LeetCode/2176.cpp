#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        const int N = nums.size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1 ; j < N; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};