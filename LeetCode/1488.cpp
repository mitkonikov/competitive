#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int N = rains.size();
        vector<int> ans(N, 1);
        set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++) {
            if (rains[i] == 0) {
                st.insert(i);
            } else {
                ans[i] = -1;
                if (mp.count(rains[i])) {
                    // smallest index >= last rain
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it == st.end()) return {};
                    ans[*it] = rains[i];
                    st.erase(it);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};