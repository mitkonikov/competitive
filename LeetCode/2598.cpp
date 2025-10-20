#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> frqmod(value);
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] < 0) nums[i] += (-(nums[i] / value) + 1) * value;
            frqmod[nums[i] % value]++;
        }
        vector<int> ptr(value, 0);
        for (int ans = 0; ans < N; ans++) {
            const int id = ans % value;
            if (ptr[id] < frqmod[id]) {
                ptr[id]++;
            } else {
                return ans;
            }
        }
        return N;
    }
};