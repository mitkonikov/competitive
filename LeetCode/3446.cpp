#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int N = grid.size();
        for (int i = 0; i < N; i++) {
            vector<int> diag;
            for (int j = 0; i + j < N; j++) {
                diag.push_back(grid[i+j][j]);
            }
            sort(diag.rbegin(), diag.rend());
            for (int j = 0; j + i < N; j++) {
                grid[i+j][j] = diag[j];
            }
        }
        for (int j = 1; j < N; j++) {
            vector<int> diag;
            for (int i = 0; i + j < N; i++) {
                diag.push_back(grid[i][i+j]);
            }
            sort(diag.begin(), diag.end());
            for (int i = 0; i + j < N; i++) {
                grid[i][i+j] = diag[i];
            }
        }
        return grid;
    }
};