#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int N = grid[0].size();
        vector<vector<long long>> pref(2, vector<long long>(N, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                if (j == 0) pref[i][j] = grid[i][j];
                else pref[i][j] = pref[i][j-1] + grid[i][j];
            }
        }
        long long ans = 1e18;
        for (int i = 0; i < N; i++) {
            // switch here
            // pref[0] at range(i + 1, N)
            // pref[1] at range(0, i - 1)
            const long long r1 = pref[0][N-1] - pref[0][i];
            const long long r2 = (i - 1 >= 0 ? pref[1][i-1] : 0);
            ans = min(ans, max(r1, r2));
        }
        return ans;
    }
};