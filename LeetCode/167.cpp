#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int N = numbers.size();
        for (int i = 0; i < N; i++) {
            int f = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), f);
            if (it == numbers.end()) continue;
            if (*it == f) return { i + 1, (int)(it - numbers.begin() + 1) };
        }
        return { -1, -1 };
    }
};