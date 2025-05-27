#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    inline ll calc(ll n) {
        return (ll)n * (n - 1) / 2;
    }

    long long countGood(vector<int>& nums, int k) {
        const int N = nums.size();
        map<int, int> frq;
        ll current_ans = 0;
        int ptr = 0;
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            frq[nums[i]]++;
            current_ans -= calc(frq[nums[i]] - 1);
            current_ans += calc(frq[nums[i]]);

            while (current_ans >= k && ptr < i) {
                current_ans -= calc(frq[nums[ptr]]);
                current_ans += calc(frq[nums[ptr]] - 1);
                frq[nums[ptr]]--;
                ptr++;
                if (current_ans < k) {
                    // revert
                    ptr--;
                    frq[nums[ptr]]++;
                    current_ans += calc(frq[nums[ptr]]);
                    current_ans -= calc(frq[nums[ptr]] - 1);
                    break;
                }
            }

            if (current_ans >= k) {
                ans += ptr + 1;
            }
        }
        return ans;
    }
};