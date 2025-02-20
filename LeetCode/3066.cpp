#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<ll> s;
        const int N = nums.size();
        for (int i = 0; i < N; i++) s.insert(nums[i]);
        int ans = 0;
        while (s.size() >= 2 && *s.begin() < k) {
            auto x = *s.begin();
            s.erase(s.begin());
            auto y = *s.begin();
            s.erase(s.begin());
            s.insert((ll)min(x, y) * 2 + max(x, y));
            ans++;
        }
        return ans;
    }
};