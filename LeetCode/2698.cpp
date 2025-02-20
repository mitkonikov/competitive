#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool part(string& s, int i, int num_till, int sum, int target) {
        if (i == s.size()) {
            return (num_till + sum == target);
        }

        bool ok1 = part(s, i + 1, num_till * 10 + (s[i] - '0'), sum, target);
        bool ok2 = part(s, i + 1, (s[i] - '0'), sum + num_till, target);
        return ok1 || ok2;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int t = i * i;
            string s = to_string(t);
            if (part(s, 0, 0, 0, i)) {
                ans += t;
            }
        }
        return ans;
    }
};