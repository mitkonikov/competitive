#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        const int N = nums.size();
        vector<int> A(nums);
        for (int i = 0; i < N && A.size() > 1; i++) {
            vector<int> new_nums;
            for (int j = 0; j < A.size() - 1; j++) {
                new_nums.push_back((A[j] + A[j+1]) % 10);
            }
            A.swap(new_nums);
        }
        return A[0];
    }
};