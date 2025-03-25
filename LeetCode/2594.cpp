#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        const int N = ranks.size();
        ll L = 0, R = 1e18 + 10;
        while (R - L > 1) {
            ll M = L + (R - L) / 2;
            ll repaired = 0;
            for (int i = 0; i < N; i++) {
                // time = ranks[i] * N^2
                // N^2 = time / ranks[i]
                // N = sqrt(time / ranks[i])
                int n = sqrt(M / ranks[i]);
                repaired += n;
            }
            if (repaired >= cars) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
};