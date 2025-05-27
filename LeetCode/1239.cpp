#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<string>& str, vector<int>& frq, int i) {
        if (i >= str.size()) return 0;
        int ans = 0;
        for (int j = 0; j < str[i].size(); j++) frq[str[i][j] - 'a']++;
        bool ok = true;
        int count = 0;
        for (int j = 0; j < 26; j++) {
            ok &= frq[j] <= 1;
            count += frq[j];
        }
        if (ok) ans = max({ ans, count, solve(str, frq, i + 1) });
        for (int j = 0; j < str[i].size(); j++) frq[str[i][j] - 'a']--;
        ans = max(ans, solve(str, frq, i + 1));
        return ans;
    }

    int maxLength(vector<string>& arr) {
        vector<int> frq(26, 0);
        return solve(arr, frq, 0);
    }
};