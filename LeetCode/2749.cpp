#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        #define ll long long
        ll k = 1;
        while (true) {
            ll x = num1 - k * num2;
            if (x < k) return -1;
            if (k >= __builtin_popcountll(x)) return k;
            k++;
        }
        return -1;
    }
};