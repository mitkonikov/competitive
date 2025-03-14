#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.size();
        vector<vector<int>> pref(N, vector<int>(3, 0));
        for (int i = 0; i < N; i++) {
            pref[i][s[i] - 'a']++;
            if (i) for (int j = 0; j < 3; j++) {
                pref[i][j] += pref[i-1][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int L = i, R = N - 1;
            while (R - L > 1) {
                int M = (R + L) / 2;
                bool ok = true;
                for (int j = 0; j < 3; j++) {
                    ok &= (pref[M][j] - (i?pref[i - 1][j]:0) > 0);
                }
                if (ok) {
                    R = M;
                } else {
                    L = M;
                }
            }
            bool ok = true;
            for (int j = 0; j < 3; j++) {
                ok &= (pref[R][j] - (i?pref[i - 1][j]:0) > 0);
            }
            if (ok) {
                ans += (N - R);
            }
        }
        return ans;
    }
};