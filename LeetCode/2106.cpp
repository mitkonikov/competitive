#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int N = fruits.size();
        vector<int> pref(N);
        for (int i = 0; i < N; i++) {
            if (i) pref[i] = pref[i-1] + fruits[i][1];
            else pref[i] = fruits[i][1];
        }
        auto range = [&](int L, int R) {
            return pref[R] - (L-1>=0 ? pref[L-1] : 0);
        };
        int lb = -1, up = -1;
        for (int i = 0; i < N; i++) {
            if (fruits[i][0] <= startPos) lb = i;
        }
        for (int i = N - 1; i >= 0; i--) {
            if (fruits[i][0] >= startPos) up = i;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            const int pos = fruits[i][0];
            if (abs(startPos - pos) > k) continue;
            if (startPos == pos) {
                ans = max(ans, fruits[i][1]);
                continue;
            }
            const int leftover = k - abs(startPos - pos);
            if (pos < startPos) {
                int L = i, R = N;
                while (R - L > 1) {
                    int M = (R + L) / 2;
                    if (fruits[M][0] <= pos+leftover) {
                        L = M;
                    } else {
                        R = M;
                    }
                }
                ans = max(ans, range(i, L));
                if (lb != -1) ans = max(ans, range(i, lb));
            } else {
                int L = 0, R = i+1;
                while (R - L > 1) {
                    int M = (R + L) / 2;
                    if (fruits[i-M][0] >= pos-leftover) {
                        L = M;
                    } else {
                        R = M;
                    }
                }
                ans = max(ans, range(i-L, i));
                if (up != -1) ans = max(ans, range(up, i));
            }
        }
        return ans;
    }
};