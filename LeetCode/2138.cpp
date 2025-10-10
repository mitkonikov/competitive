#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        ans.push_back(string(1, s[0]));
        for (int i = 1; i < s.size(); i++) {
            if (ans.back().size() == k) {
                ans.push_back(string(1, s[i]));
                continue;
            }
            ans.back() += s[i];
        }
        while (ans.back().size() < k) ans.back() += fill;
        return ans;
    }
};