#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string vowels = "aeiou";
        auto counts = [&](const string& s) {
            bool start = false, end = false;
            for (auto e : vowels) if (s[0] == e) start = true;
            for (auto e : vowels) if (s.back() == e) end = true;
            return start && end;
        };
        int N = words.size();
        vector<int> pref(N);
        for (int i = 0; i < N; i++) {
            if (counts(words[i])) pref[i]++;
        }
        for (int i = 1; i < N; i++) {
            pref[i] += pref[i-1];
        }
        int Q = queries.size();
        vector<int> ans(Q);
        for (int q = 0; q < Q; q++) {
            int L = queries[q][0];
            int R = queries[q][1];
            ans[q] = pref[R] - (L>0 ? pref[L-1] : 0);
        }
        return ans;
    }
};