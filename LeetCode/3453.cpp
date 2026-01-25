#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        const int N = squares.size();
        double L = 0, R = 1e9 + 10;
        for (int iter = 0; iter < 100; iter++) {
            double MID = L + (R - L) / 2;
            double down = 0;
            double up = 0;
            for (int i = 0; i < N; i++) {
                double y1 = max((double)0, min((double)squares[i][1] + squares[i][2], MID) - squares[i][1]);
                double x1 = squares[i][2];
                down += x1 * y1;
                double y2 = max((double)0, squares[i][1] + squares[i][2] - max(MID, (double)squares[i][1]));
                double x2 = squares[i][2];
                up += x2 * y2;
            }
            if (down >= up) {
                R = MID;
            } else {
                L = MID;
            }
        }
        return L;
    }
};