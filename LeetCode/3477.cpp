#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int F = fruits.size();
        const int B = baskets.size();
        vector<bool> visited(B);
        int ans = 0;
        for (int i = 0; i < F; i++) {
            bool placed = false;
            for (int j = 0; j < B; j++) {
                if (visited[j]) continue;
                if (baskets[j] >= fruits[i]) {
                    visited[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) ans++;
        }
        return ans;
    }
};