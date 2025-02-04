#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int N = nums.size();
        for (int start = 0; start < N; start++) {
            bool ok = true;
            for (int i = 0; i < N - 1 && ok; i++) {
                if (nums[(start+i)%N] > nums[(start+i+1)%N]) ok = false;
            }
            if (ok) return true;
        }
        return false;
    }
};