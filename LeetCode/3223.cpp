#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int N = s.size();
        vector<int> frq(26, 0);
        for (int i = 0; i < N; i++) {
            frq[s[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (frq[i] >= 3) {
                if (frq[i] & 1) {
                    ans += 1;
                } else {
                    ans += 2;
                }
            } else {
                ans += frq[i];
            }
        }
        return ans;
    }
};