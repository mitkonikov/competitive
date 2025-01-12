#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int N = s.size();
        int bal = 0;
        int mn = 0, mn_id = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') bal++;
            else bal--;
            if (bal < mn) {
                mn = bal;
                mn_id = i;
            }
        }
        for (int i = 0; mn < 0 && i <= mn_id; i++) {
            if (s[i] == ')' && locked[i] == '0') {
                s[i] = '(';
                mn += 2;
            }
        }
        if (mn < 0) return false;
        int bal2 = 0;
        bool failed = false;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') bal2++;
            else bal2--;
            if (bal2 < 0) failed = true;
        }
        if (!failed && bal2 == 0) return true;
        for (int i = N - 1; bal2 > 0 && i >= 0; i--) {
            if (s[i] == '(' && locked[i] == '0') {
                s[i] = ')';
                bal2 -= 2;
            }
        }
        int bal3 = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') bal3++;
            else bal3--;
            if (bal3 < 0) return false;
        }
        return bal3 == 0;
    }
};