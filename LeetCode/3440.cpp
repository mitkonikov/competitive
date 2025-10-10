#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        startTime.insert(startTime.begin(), 0);
        endTime.insert(endTime.begin(), 0);
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        const int N = startTime.size();
        multiset<int> back;
        for (int i = N - 2; i >= 1; i--) {
            back.insert(startTime[i+1] - endTime[i]);
        }
        int mx_front = 0;
        int ans = 0;
        for (int i = 1; i <= N - 2; i++) {
            auto it = back.find(startTime[i+1] - endTime[i]);
            if (it != back.end()) {
                back.erase(it);
            }
            int diff = startTime[i+1] - endTime[i-1];
            int me = endTime[i] - startTime[i];
            ans = max(ans, diff - me);
            if (me <= mx_front) {
                ans = max(ans, diff);
            }
            if (back.size() && me <= *prev(back.end())) {
                ans = max(ans, diff);
            }
            mx_front = max(mx_front, startTime[i] - endTime[i-1]);
        }
        return ans;
    }
};