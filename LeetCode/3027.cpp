#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();
        int ans = 0;
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < N; i++) {
            int mxY = -1e9 - 10;
            for (int j = i + 1; j < N; j++) {
                if (points[j][1] > points[i][1]) continue;
                if (points[j][1] <= mxY) continue;
                ans++;
                mxY = max(mxY, points[j][1]);
            }
        }
        return ans;
    }
};