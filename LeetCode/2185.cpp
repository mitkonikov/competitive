#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].substr(0, pref.size()) == pref) {
                ans++;
            }
        }
        return ans;
    }
};