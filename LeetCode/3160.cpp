#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> frq, color;
        const int Q = queries.size();
        vector<int> ans(Q);
        for (int i = 0; i < Q; i++) {
            auto it = color.find(queries[i][0]);
            const int new_color = queries[i][1];
            if (it == color.end()) {
                color[queries[i][0]] = new_color;
                frq[new_color]++;
            } else {
                frq[it->second]--;
                if (frq[it->second] == 0) frq.erase(it->second);
                color[queries[i][0]] = new_color;
                frq[new_color]++;
            }
            ans[i] = (int)frq.size();
        }
        return ans;
    }
};