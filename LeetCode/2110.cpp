#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long count = 1;
        const int N = prices.size();
        for (int i = 1; i < N; i++) {
            if (prices[i] != prices[i-1] - 1) {
                ans += (count * (count + 1)) / 2;
                count = 1;
            } else {
                count++;
            }
        }
        ans += (count * (count + 1)) / 2;
        return ans;
    }
};