#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>> ind(26);
        int N = s.size();
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int mir = (26 - (s[i] - 'a') - 1);
            if (ind[mir].size()) {
                ans += i - ind[mir].back();
                ind[mir].pop_back();
            } else {
                ind[s[i] - 'a'].push_back(i);
            }
        }
        return ans;
    }
};