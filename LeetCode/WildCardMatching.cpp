#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int S = s.size();
        int P = p.size();
        vector<vector<bool>> can(P + 1, vector<bool>(S + 1, 0));
        can[0][0] = 1;
        s = "@" + s;
        p = "@" + p;
        for (int i = 1; i <= P; i++) {
            if (p[i] == '*') can[i][0] = can[i-1][0];
            else break;
        }
        for (int i = 1; i <= P; i++) {
            for (int j = 1; j <= S; j++) {
                if (p[i] == s[j] || p[i] == '?') {
                    can[i][j] = can[i][j] || can[i-1][j-1];
                } else if (p[i] == '*') {
                    can[i][j] = can[i][j] || can[i-1][j] || can[i][j-1];
                } else {
                    can[i][j] = 0;
                }
            }
        }
        return can[P][S];
    }
};