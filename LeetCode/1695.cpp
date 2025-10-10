#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        vector<ll> pref(N);
        pref[0] = nums[0];
        for (int i = 1; i < N; i++) {
            pref[i] = pref[i-1] + nums[i];
        }
        vector<int> last(1e4 + 100, -1);
        int mx = -1;
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            mx = max(mx, last[nums[i]]);
            const ll cur = pref[i] - (mx >= 0 ? pref[mx] : 0);
            ans = max(ans, cur);
            last[nums[i]] = i;
        }
        return ans;
    }
};