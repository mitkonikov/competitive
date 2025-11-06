#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> p(m, vector<int>(n, 0));
        const int G = guards.size();
        const int W = walls.size();
        for (int i = 0; i < G; i++) p[guards[i][0]][guards[i][1]] = 1;
        for (int i = 0; i < W; i++) p[walls[i][0]][walls[i][1]] = -1;
        vector<vector<int>> out(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int g = false;
            for (int j = 0; j < n; j++) {
                if (p[i][j] == 1) g = true;
                out[i][j] |= g;
                if (p[i][j] == -1) g = false;
            }
        }
        for (int i = 0; i < m; i++) {
            int g = false;
            for (int j = n - 1; j >= 0; j--) {
                if (p[i][j] == 1) g = true;
                out[i][j] |= g;
                if (p[i][j] == -1) g = false;
            }
        }
        for (int i = 0; i < n; i++) {
            int g = false;
            for (int j = 0; j < m; j++) {
                if (p[j][i] == 1) g = true;
                out[j][i] |= g;
                if (p[j][i] == -1) g = false;
            }
        }
        for (int i = 0; i < n; i++) {
            int g = false;
            for (int j = m - 1; j >= 0; j--) {
                if (p[j][i] == 1) g = true;
                out[j][i] |= g;
                if (p[j][i] == -1) g = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += p[i][j] == 0 && !out[i][j];
            }
        }
        return ans;
    }
};