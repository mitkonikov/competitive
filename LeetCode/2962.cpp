#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct MonotonicStackRollback {
    struct Change {
        bool add;
        int index;
    };
    
    vector<int> st;
    vector<vector<Change>> changes;

    MonotonicStackRollback(vector<int>& nums) {
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            changes.push_back({ });
            while (st.size() && nums[st.back()] < nums[i]) {
                changes.back().push_back({ false, st.back() });
                st.pop_back();
            }
            st.push_back(i);
            changes.back().push_back({ true, i });
        }
    }

    void revert() {
        if (changes.empty()) return;
        reverse(changes.back().begin(), changes.back().end());
        for (auto& change: changes.back()) {
            if (change.add) {
                st.pop_back();
            } else {
                st.push_back(change.index);
            }
        }
        changes.pop_back();
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> nums2 = nums;
        nums2.push_back(1e9);
        reverse(nums2.begin(), nums2.end());
        MonotonicStackRollback MSR(nums2);
        vector<pair<int, vector<int>>> st;
        st.push_back({ 1e9, { -1 }});
        ll ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < N; i++) {
            if (i) MSR.revert();
            while (st.size() && st.back().first < nums[i]) {
                st.pop_back();
            }
            if (st.size() && st.back().first == nums[i]) {
                st.back().second.push_back(i);
            } else {
                st.push_back({ nums[i], { i } });
            }
            if (st.back().second.size() < k) continue;
            if (nums[i] != mx) continue; // comment this line to solve HARD version
            int L = st.rbegin()[1].second.back() + 1;
            int R = st.back().second.rbegin()[k-1];
            ll left = R - L + 1;
            ll right = (N - MSR.st.rbegin()[1]) - i;
            ans += left * right;
        }
        return ans;
    }
};