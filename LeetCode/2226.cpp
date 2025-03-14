#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        const int N = candies.size();
        ll L = 0, R = 1e12 + 10;
        while (R - L > 1) {
            ll M = L + (R - L) / 2;
            ll count = 0;
            for (int i = 0; i < N; i++) {
                count += candies[i] / M;
            }
            if (count >= k) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
};