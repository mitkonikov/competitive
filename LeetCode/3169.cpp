#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        const int N = meetings.size();
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> merged{ meetings[0] };
        for (int i = 1; i < N; i++) {
            if (meetings[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } else {
                merged.push_back(meetings[i]);
            }
        }
        int ans = days;
        for (int i = 0; i < merged.size(); i++) {
            if (merged[i][0] > days) break;
            merged[i][1] = min(merged[i][1], days);
            ans -= merged[i][1] - merged[i][0] + 1;
        }
        return ans;
    }
};