#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mx(26, 0);
        for (int i = 0; i < words2.size(); i++) {
            vector<int> frq(26, 0);
            for (int j = 0; j < words2[i].size(); j++) {
                frq[words2[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                mx[k] = max(mx[k], frq[k]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < words1.size(); i++) {
            bool ok = true;
            vector<int> frq(26, 0);
            for (int j = 0; j < words1[i].size(); j++) {
                frq[words1[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                ok &= (frq[k] >= mx[k]);
            }
            if (ok) ans.push_back(words1[i]);
        }
        return ans;
    }
};