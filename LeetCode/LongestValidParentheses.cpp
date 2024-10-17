#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
        vector<int> b(2 * N + 100, -2);
        int balance = 0;
        int ans = 0;
        b[N + 0] = -1;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                balance++;
                b[N + balance] = i;
            } else {
                balance--;
                int got = b[N + balance];
                if (got != -2) {
                    ans = max(ans, i - got);
                } else {
                    b[N + balance] = i;
                }
            }
        }
        return ans;
    }
};