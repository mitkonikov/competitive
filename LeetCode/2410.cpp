#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int p = 0, t = 0, ans = 0;
        while (p < players.size() && t < trainers.size()) {
            if (players[p] <= trainers[t]) {
                p++; t++; ans++;
            } else {
                t++;
            }
        }
        return ans;
    }
};