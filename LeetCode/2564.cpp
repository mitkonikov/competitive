#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int, pair<int, int>> memo;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= 30; j++) {
                string sub = s.substr(i, j);
                if (j != sub.size()) break;
                int bin = 0;
                for (int k = 0; k < j; k++) {
                    if (sub[j-k-1] == '1') bin |= (1 << k);
                }
                auto it = memo.find(bin);
                if (it == memo.end()) {
                    memo[bin] = { i, j };
                } else if (it->second.second > j) {
                    memo[bin] = { i, j };
                }
            }
        }
        int Q = queries.size();
        vector<vector<int>> ans;
        for (int i = 0; i < Q; i++) {
            int bin = queries[i][0] ^ queries[i][1];
            auto it = memo.find(bin);
            if (it == memo.end()) {
                ans.push_back({ -1, -1 });
            } else {
                const int L = it->second.first;
                const int len = it->second.second;
                ans.push_back({ L, L + len - 1 });
            }
        }
        return ans;
    }
};