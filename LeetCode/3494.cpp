#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long ans = 0;
        int N = skill.size();
        int M = mana.size();
        vector<long long> last_times(N);
        long long time = 0;
        for (int i = 0; i < N; i++) {
            time += (long long)skill[i] * mana[0];
            last_times[i] = time;
        }
        for (int m = 1; m < M; m++) {
            long long start_time = last_times[N - 1];
            for (int n = N - 2; n >= 0; n--) {
                long long time_needed = (long long)skill[n] * mana[m];
                if (last_times[n] + time_needed > start_time) {
                    start_time = last_times[n];
                } else {
                    start_time = start_time - time_needed;
                }
            }
            for (int n = 0; n < N; n++) {
                start_time += (long long)skill[n] * mana[m];
                last_times[n] = start_time;
            }
        }
        return last_times[N - 1];
    }
};