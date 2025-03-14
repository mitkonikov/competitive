#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers{ 1 };
        while (powers.back() * 3 < 1e7 + 100) {
            powers.push_back(powers.back() * 3);
        }
        const int N = powers.size();
        for (int mask = 0; mask < (1 << N); mask++) {
            long long sum = 0;
            for (int j = 0; j < N; j++) {
                if (mask & (1 << j)) {
                    sum += powers[j];
                }
            }
            if (sum == n) {
                return true;
            }
        }
        return false;
    }
};