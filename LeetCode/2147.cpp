#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string S) {
        const int MOD = 1e9 + 7;
        const int N = S.size();
        int seats = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'S') seats++;
        }
        if (seats % 2 == 1 || seats == 0) return 0;
        seats = 0;
        int count = 0;
        int ans = 1;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'S') {
                if (seats == 2) {
                    ans = ((long long)ans * (count + 1)) % MOD;
                    seats = 0;
                    count = 0;
                }
                seats++;
            } else {
                if (seats == 2) {
                    count++;
                }
            }
        }
        return ans;
    }
};