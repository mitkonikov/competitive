#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(const string& s, int x, int y) {
        // bbbababbababbaabababbaaaaa
        const int N = s.size();
        long long ans = 0;
        long long as = 0, bs = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'a') {
                as++;
            } else {
                if (as > 0) {
                    as--;
                    ans += x;
                } else {
                    bs++;
                }
            }
        }
        ans += min(as, bs) * y;
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        const int N = s.size();
        if (y > x) {
            swap(x, y);
            for (int i = 0; i < N; i++) {
                if (s[i] == 'a') s[i] = 'b';
                else if (s[i] == 'b') s[i] = 'a';
            }
        }
        s += "@";
        string cur = "";
        long long ans = 0;
        for (int i = 0; i < N + 1; i++) {
            if (s[i] != 'a' && s[i] != 'b') {
                if (cur.size()) ans += solve(cur, x, y);
                cur = "";
            } else {
                cur += s[i];
            }
        }
        return ans;
    }
};