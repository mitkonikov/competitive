#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> frq(26);
        for (int i = 0; i < word.size(); i++) {
            frq[word[i] - 'a']++;
        }
        sort(frq.rbegin(), frq.rend());
        while (frq.back() == 0) frq.pop_back();
        const int D = frq.size();
        int deleted_mins = 0;
        int ans = 1e9;
        for (int d = 0; d < D; d++) {
            int cur = deleted_mins;
            for (int i = 0; i < frq.size(); i++) {
                if (frq[i] >= frq.back() + k) {
                    cur += frq[i] - (frq.back() + k);
                }
            }

            deleted_mins += frq.back();
            frq.pop_back();
            ans = min(ans, cur);
        }
        return ans;
    }
};