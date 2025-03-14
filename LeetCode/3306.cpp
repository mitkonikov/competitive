#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        const int N = word.size();
        vector<vector<int>> pref(N, vector<int>(26, 0));
        for (int i = 0; i < N; i++) {
            pref[i][word[i]-'a']++;
            if (i) for (int j = 0; j < 26; j++) {
                pref[i][j] += pref[i-1][j];
            }
        }
        auto sum_range = [&](int L, int R, int i) {
            return pref[R][i] - (L > 0 ? pref[L-1][i] : 0);
        };
        string v = "aeiou";
        auto vowels = [&](int L, int R) {
            int sum = 0;
            for (auto w : v) {
                sum += sum_range(L, R, w - 'a');
            }
            return sum;
        };
        auto good = [&](int L, int R) {
            bool ok = true;
            for (auto w: v) {
                ok &= sum_range(L, R, w - 'a') > 0;
            }
            return ok;
        };
        auto conson = [&](int L, int R) {
            return (R - L + 1) - vowels(L, R);
        };
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            // begining at i, find where k cons are
            int L = i + k, R = N;
            while (R - L > 1) {
                int M = (R + L) / 2;
                int cons = conson(i, M);
                if (cons <= k) {
                    L = M;
                } else {
                    R = M;
                }
            }
            int L1 = i + k, R1 = N;
            while (R1 - L1 > 1) {
                int M = (R1 + L1) / 2;
                int cons = conson(i, M);
                if (cons < k || !good(i, M)) {
                    L1 = M;
                } else {
                    R1 = M;
                }
            }

            if (R1 >= N) continue;
            if (conson(i, L) == k && good(i, L) && conson(i, R1) == k && good(i, R1)) {
                // L1 + 1 -> L
                int cur = max(0, L - R1 + 1);
                ans += cur;
            }
        }
        return ans;
    }
};