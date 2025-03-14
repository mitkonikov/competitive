#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int N = grid.size();
        vector<int> frq(N * N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                frq[grid[i][j] - 1]++;
            }
        }
        int a = 0, b = 0;
        for (int i = 0; i < N * N; i++) {
            if (frq[i] == 2) a = i;
            else if (frq[i] == 0) b = i;
        }
        return vector<int>{ a + 1, b + 1 };
    }
};