#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string S = to_string(num);
        const int N = S.size();
        vector<int> frq(10);
        for (int i = 0; i < N; i++) {
            frq[S[i]-'0']++;
        }
        int mx = 0, mn = INT_MAX;
        for (char from = '0'; from <= '9'; from++) {
            if (frq[from - '0'] == 0) continue;
            for (char to = '0'; to <= '9'; to++) {
                string newS = S;
                for (int i = 0; i < N; i++) {
                    if (newS[i] == from) newS[i] = to;
                }
                reverse(newS.begin(), newS.end());
                while (newS.size() > 1 && newS.back() == '0') newS.pop_back();
                reverse(newS.begin(), newS.end());
                int cur = stoi(newS);
                mx = max(mx, cur);
                mn = min(mn, cur);
            }
        }
        return mx - mn;
    }
};