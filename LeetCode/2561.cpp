#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, vector<int>> b1, b2;
        set<int> all;
        for (int i = 0; i < basket1.size(); i++) {
            b1[basket1[i]].push_back(i);
            all.insert(basket1[i]);
        }
        for (int i = 0; i < basket2.size(); i++) {
            b2[basket2[i]].push_back(i);
            all.insert(basket2[i]);
        }
        vector<int> r;
        for (auto& el : all) {
            auto& b1_vec = b1[el];
            auto& b2_vec = b2[el];
            const int c1 = b1_vec.size();
            const int c2 = b2_vec.size();
            if (c1 > c2) {
                if ((c1 - c2) % 2 != 0) {
                    return -1;
                }
                for (int j = 0; j < (c1 - c2) / 2; j++) {
                    r.push_back(el);
                }
            } else if (c2 > c1) {
                if ((c2 - c1) % 2 != 0) {
                    return -1;
                }
                for (int j = 0; j < (c2 - c1) / 2; j++) {
                    r.push_back(el);
                }
            }
        }
        int mn = *all.begin();
        sort(r.begin(), r.end());
        long long ans = 0;
        for (int i = 0; i < r.size() / 2; i++) {
            ans += min(2 * mn, r[i]);
        }
        return ans;
    }
};