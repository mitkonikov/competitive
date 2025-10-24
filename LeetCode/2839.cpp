#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int r1 = 0; r1 < 2; r1++) {
            swap(s1[0], s1[2]);
            for (int r2 = 0; r2 < 2; r2++) {
                swap(s1[1], s1[3]);
                if (s1 == s2) return true;
            }
        }
        return false;
    }
};