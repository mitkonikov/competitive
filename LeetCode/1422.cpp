#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int N = s.size();
        vector<int> pref(N), suff(N);
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') pref[i]++;
            if (s[i] == '1') suff[i]++;
        }
        for (int i = 1; i < N; i++) {
            pref[i] += pref[i-1];
        }
        for (int i = N - 2; i >= 0; i--) {
            suff[i] += suff[i+1];
        }
        int ans = 0;
        for (int i = 0; i < N - 1; i++) {
            ans = max(ans, pref[i] + suff[i + 1]);
        }
        return ans;
    }
};