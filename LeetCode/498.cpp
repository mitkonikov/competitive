#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int N = mat.size();
        const int M = mat[0].size();
        vector<int> result;
        result.reserve(N * M);
        vector<vector<int>> diags(N + M + 10);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                diags[i + j].push_back(mat[i][j]);
            }
        }
        for (int d = 0; d < diags.size(); d++) {
            if (d % 2 == 0) reverse(diags[d].begin(), diags[d].end());
            for (auto& el : diags[d]) result.push_back(el);
        }
        return result;
    }
};