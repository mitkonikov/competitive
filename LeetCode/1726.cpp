#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0;
        map<int, int> frq;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                frq[nums[i] * nums[j]]++;
            }
        }
        for (auto [k, v] : frq) {
            if (v >= 2) {
                int pairs = v * (v - 1) / 2;
                ans += 8 * pairs;
            }
        }
        return ans;
    }
};