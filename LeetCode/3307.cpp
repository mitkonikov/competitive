#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int MSB = 0;
        for (int i = 0; i < 62; i++) {
            if ((1LL << i) & k) {
                MSB = i;
            }
        }
        int count = 0;
        for (int i = MSB; i >= 0; i--) {
            if (((1LL << i) & k) > 0 && operations[i]) {
                count++;
            }
        }
        return (char)('a' + (count % 26));
    }
};