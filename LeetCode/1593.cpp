#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        int N = s.size();
        set<string> t;
        int ans = 0;
        for (int mask = 0; mask < (1 << (N - 1)); mask++) {
            t.clear();
            string S = s.substr(0, 1);
            bool fail = false;
            for (int i = 0; i < N; i++) {
                if (i == N - 1 || ((mask & (1 << i)) > 0)) {
                    if (t.count(S)) {
                        fail = true;
                        break;
                    }

                    t.insert(S);
                    if (i < N - 1) S = s[i + 1];
                } else {
                    S += s[i + 1];
                }
            }

            if (!fail) {
                ans = max(ans, (int)t.size());
            }
        }

        return ans;
    }
};