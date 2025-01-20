#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        const int M = nums2.size();
        vector<int> bits(31, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= 30; j++) {
                if (nums2[i] & (1 << j)) bits[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= 30; j++) {
                const int cnt_on = bits[j];
                const int cnt_off = M - bits[j];
                const int cnt = ((nums1[i] & (1 << j)) > 0 ? cnt_off : cnt_on);
                if (cnt & 1) ans ^= (1 << j);
            }
        }
        return ans;
    }
};