#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int count = 0;
        const int N = s1.size();
        string mismatch1 = "", mismatch2 = "";
        for (int i = 0; i < N; i++) {
            if (s1[i] != s2[i]) {
                count++;
                mismatch1 += s1[i];
                mismatch2 += s2[i];
            }
        }
        if (count != 2) return false;
        sort(mismatch1.begin(), mismatch1.end());
        sort(mismatch2.begin(), mismatch2.end());
        return mismatch1 == mismatch2;
    }
};