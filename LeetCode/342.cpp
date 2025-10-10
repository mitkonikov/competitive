#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        long long res = 1;
        for (int i = 1; i <= 30; i++) {
            res *= 4;
            if (n == res) return true;
        }
        return false;
    }
};