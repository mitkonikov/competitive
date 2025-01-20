#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int N = mat.size();
        const int M = mat[0].size();
        vector<int> rev(N * M);
        vector<pair<int, int>> coords;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                coords.push_back({ i, j });
            }
        }
        for (int i = 0; i < N * M; i++) {
            rev[arr[i] - 1] = i;
        }
        sort(coords.begin(), coords.end(), [&](auto a, auto b) {
            return rev[mat[a.first][a.second] - 1] < rev[mat[b.first][b.second] - 1];
        });
        vector<int> row(N), col(M);
        for (int i = 0; i < N * M; i++) {
            auto [x, y] = coords[i];
            row[x]++;
            col[y]++;
            if (row[x] == M) return i;
            if (col[y] == N) return i;
        }
        return -1;
    }
};