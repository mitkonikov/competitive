#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        target.push_back(0);
        const int N = target.size();
        stack<pair<int, int>> st;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (i && target[i] == target[i-1]) continue;
            int last_start = -1;
            int last_val = -1;
            vector<int> steps;
            while (st.size() && st.top().first > target[i]) {
                auto [val, start] = st.top();
                st.pop();
                if (last_val == val) continue;
                last_val = val;
                last_start = start;
                steps.push_back(val);
            }
            steps.push_back(target[i]);
            for (int j = 1; j < steps.size(); j++) {
                ans += steps[j-1] - steps[j];
            }
            if (steps.back() > target[i] && (st.empty() || st.top().first != target[i])) {
                st.push({ steps.back(), last_start });
            }
            st.push({ target[i], i });
        }
        return ans;
    }
};