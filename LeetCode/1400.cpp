#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> frq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            frq[s[i] - 'a']++;
        }
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            odd += frq[i] % 2;
        }
        if (k < odd) return false;
        k -= odd;
        int sum = (int)s.size() - odd;
        if (sum >= k) return true;
        return false;
    }
};