#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            ans += s[i];
            if (ans.size() >= part.size() && ans.substr(ans.size() - part.size()) == part) {
                for (int k = 0; k < part.size(); k++) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};