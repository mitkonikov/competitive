#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        const int N = arr.size();
        vector<int> last(32, -1);
        unordered_set<int> ans;
        for (int i = 0; i < N; i++) {
            vector<int> lasts;
            for (int j = 0; j < 30; j++) {
                if (((1 << j) & arr[i]) == 0) {
                    if (last[j] != -1) {
                        lasts.push_back(last[j]);
                    }
                }
            }
            sort(lasts.rbegin(), lasts.rend());
            int cur = arr[i];
            ans.insert(cur);
            for (auto last : lasts) {
                cur |= arr[last];
                ans.insert(cur);
            }
            
            for (int j = 0; j < 30; j++) {
                if ((1 << j) & arr[i]) {
                    last[j] = i;
                }
            }
        }
        return (int)ans.size();
    }
};