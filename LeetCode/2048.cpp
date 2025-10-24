#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> frq(10);
        while (true) {
            n++;
            fill(frq.begin(), frq.end(), 0);
            string s = to_string(n);
            for (auto& ch : s) frq[ch - '0']++;
            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (frq[i] > 0) {
                    ok &= frq[i] == i;
                }
            }
            if (ok) return n;
        }
        return -1;
    }
};