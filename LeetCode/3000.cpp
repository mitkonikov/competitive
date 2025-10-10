#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long mx_diag = 0;
        long long mx_area = 0;
        int mx_id = -1;
        const int N = dimensions.size();
        for (int i = 0; i < N; i++) {
            const int W = dimensions[i][0];
            const int H = dimensions[i][1];
            long long diag = (long long)W * W + (long long)H * H;
            long long area = (long long)W * H;
            if (diag > mx_diag) {
                mx_diag = diag;
                mx_id = i;
                mx_area = area;
            } else if (diag == mx_diag && area > mx_area) {
                mx_diag = diag;
                mx_id = i;
                mx_area = area;
            }
        }
        return mx_area;
    }
};