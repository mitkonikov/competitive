#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        int ans = 0;
        const int N = s.size();
        char last = '0';
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') {
                if (last == '0') continue;
                else { ans += ones; }
            } else {
                ones++;
            }
            last = s[i];
        }
        return ans;
    }
};