#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            // try to add a zero at the end
            int last = ans[i-1];
            if (last * 10 <= n) {
                ans[i] = last * 10;
                continue;
            }
            if (last % 10 < 9 && last + 1 <= n) {
                ans[i] = last + 1;
                continue;
            }
            int new_num = last / 10 + 1;
            while (new_num % 10 == 0) {
                new_num /= 10;
            }
            ans[i] = new_num;
        }
        return ans;
    }
};