#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int N = energy.size();
        int ans = -1e9 - 100;
        for (int i = N - 1; i >= 0; i--) {
            if (i + k < N) {
                energy[i] += energy[i + k];
            }
            ans = max(ans, energy[i]);
        }
        return ans;
    }
};