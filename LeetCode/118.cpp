#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({ 1 });
        for (int i = 1; i < numRows; i++) {
            vector<int> cur{ 1 };
            for (int j = 0; j < i - 1; j++) {
                cur.push_back(ans.back()[j] + ans.back()[j+1]);
            }
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};