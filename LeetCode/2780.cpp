#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();
        vector<int> dom(N);
        map<int, int> frq;
        int count = 0;
        int current_dom = -1;
        for (int i = N - 1; i >= 0; i--) {
            frq[nums[i]]++;
            count++;
            if (frq[nums[i]] > frq[current_dom]) {
                current_dom = nums[i];
            }
            if (frq[current_dom] > count / 2) {
                dom[i] = current_dom;
            }
        }
        frq.clear();
        current_dom = -1;
        for (int i = 0; i < N - 1; i++) {
            frq[nums[i]]++;
            if (frq[nums[i]] > frq[current_dom]) {
                current_dom = nums[i];
            }
            if (frq[current_dom] > (i + 1) / 2 && current_dom == dom[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};