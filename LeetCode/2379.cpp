#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int K) {
        const int N = blocks.size();
        vector<int> pref(N);
        for (int i = 0; i < N; i++) {
            pref[i] += (blocks[i] == 'B');
            if (i) pref[i] += pref[i-1];
        }
        int ans = 1e9;
        for (int i = K - 1; i < N; i++) {
            int sum = pref[i] - (i-K>=0?pref[i-K]:0);
            ans = min(ans, K - sum);
        }
        return ans;
    }
};