#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.insert(startTime.begin(), 0);
        endTime.insert(endTime.begin(), 0);
        const int N = startTime.size();
        int ans = 0;
        vector<int> pref(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) pref[i] = endTime[i] - startTime[i];
            else pref[i] = pref[i-1] + endTime[i] - startTime[i];
        }
        for (int i = 0; i < N; i++) {
            int nx = min(i + k, N - 1);
            int reschedule = pref[nx] - pref[i];
            int e = (nx == N - 1 ? eventTime : startTime[nx + 1]);
            int s = endTime[i] + reschedule;
            ans = max(ans, e - s);
        }
        return ans;
    }
};