#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const int N = grid.size();
        const int M = grid[0].size();
        int mnX = N + 1;
        int mnY = M + 1;
        int mxX = -1;
        int mxY = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    mnX = min(mnX, i);
                    mnY = min(mnY, j);
                    mxX = max(mxX, i);
                    mxY = max(mxY, j);
                }
            }
        }
        return (mxX - mnX + 1) * (mxY - mnY + 1);
    }
};