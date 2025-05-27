#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans{ words[0] };
        const int N = words.size();
        int last = groups[0];
        for (int i = 1; i < N; i++) {
            if (groups[i] != last) {
                ans.push_back(words[i]);
                last = groups[i];
            }
        }
        return ans;
    }
};