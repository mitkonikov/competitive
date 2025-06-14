#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> frq(26);
        for (int i = 0; i < s.size(); i++) {
            frq[s[i] - 'a']++;
        }
        int mx_odd = 0, mn_even = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (frq[i] == 0) continue;
            if (frq[i] % 2 == 0) mn_even = min(mn_even, frq[i]);
            else mx_odd = max(mx_odd, frq[i]);
        }
        return mx_odd - mn_even;
    }
};