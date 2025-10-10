#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<int> bin;
        int t = k;
        while (t > 0) {
            bin.push_back(t % 2);
            t /= 2;
        }
        reverse(bin.begin(), bin.end());
        const int N = s.size();
        int ans = 0;
        int zeros = 0;
        int ptr = 0;
        int sum = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (ptr < bin.size() && sum + (1 << ptr) <= k) {
                    sum += (1 << ptr);
                    ans++;
                }
            } else {
                ans++;
            }
            ptr++;
        }
        ans = max(ans, zeros);
        return ans;
    }
};