#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string ns = "";
            for (int i = 0; i < s.size() - 1; i++) {
                ns += (char)((((s[i] - '0') + (s[i+1] - '0')) % 10) + '0');
            }
            s = ns;
        }
        return s[0] == s[1];
    }
};