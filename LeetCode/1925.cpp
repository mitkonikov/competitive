#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c2 = a * a + b * b;
                int sq = (int)sqrt(c2);
                if (sq <= n && sq * sq == c2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};