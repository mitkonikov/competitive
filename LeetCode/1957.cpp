#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string r = s.substr(0, min((int)s.size(), 2));
        for (int i = 2; i < s.size(); i++) {
            if (r.rbegin()[0] == r.rbegin()[1] && r.rbegin()[0] == s[i]) {
                continue;
            }
            r += s[i];
        }
        return r;
    }
};