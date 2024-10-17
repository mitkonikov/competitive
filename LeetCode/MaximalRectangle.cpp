#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<vector<int>> left(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j-1>=0 ? left[i][j-1] + 1 : 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == '0') continue;
                int best = left[i][j];
                for (int e = i; e >= 0; e--) {
                    best = min(best, left[e][j]);
                    ans = max(ans, best * (i-e+1));
                }
            }
        }
        return ans;
    }
};