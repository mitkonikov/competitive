#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (int i = 0; i < operations.size(); i++) {
            for (auto& el : operations[i]) {
                if (el == '-') { x--; break; }
                if (el == '+') { x++; break; }
            }
        }
        return x;
    }
};