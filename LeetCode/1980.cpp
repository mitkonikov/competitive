#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int N = nums.size();
        vector<bool> visited((1 << 16) + 100);
        for (int i = 0; i < N; i++) {
            int t = 0;
            int cur = 1;
            for (int j = nums[i].size() - 1; j >= 0; j--) {
                if (nums[i][j] == '1') t += cur;
                cur *= 2;
            }
            visited[t] = true;
        }
        const int M = nums[0].size();
        for (int i = 0; i < (1 << M); i++) {
            if (!visited[i]) {
                string ans = "";
                for (int j = 0; j < M; j++) {
                    if ((1 << j) & i) {
                        ans += "1";
                    } else {
                        ans += "0";
                    }
                }
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
        return "";
    }
};