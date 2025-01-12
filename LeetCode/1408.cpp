#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int N = words.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (words[j].size() < words[i].size()) continue;
                bool ok = false;
                for (int k = 0; k < words[j].size() - words[i].size() + 1; k++) {
                    if (words[i] == words[j].substr(k, words[i].size())) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};