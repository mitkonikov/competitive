#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, map<int, int>> rows, cols;
        const int M = buildings.size();
        for (int i = 0; i < M; i++) {
            rows[buildings[i][0]][buildings[i][1]]++;
            cols[buildings[i][1]][buildings[i][0]]++;
        }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            int ok = 0;
            {
                auto it1 = rows.find(buildings[i][0]);
                auto it2 = it1->second.find(buildings[i][1]);
                if (it2 != it1->second.begin() && it2 != prev(it1->second.end())) {
                    ok++;
                }
            }
            {
                auto it1 = cols.find(buildings[i][1]);
                auto it2 = it1->second.find(buildings[i][0]);
                if (it2 != it1->second.begin() && it2 != prev(it1->second.end())) {
                    ok++;
                }
            }
            if (ok == 2) ans++;
        }
        return ans;
    }
};