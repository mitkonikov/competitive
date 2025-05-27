#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for (auto el: nums) s.insert(el);
        if (*s.begin() >= k) return s.size() - (*s.begin() == k);
        return -1;
    }
};