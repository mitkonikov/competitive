#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        const int N = s.size();
        vector<int> last(26, -1);
        for (int i = 0; i < N; i++) {
            last[s[i] - 'a'] = i;
        }
        int current = 0;
        while (last[current] == -1) current++;
        string T = "";
        string ans = "";
        for (int i = 0; i < N; i++) {
            if (s[i] - 'a' == current) {
                ans += s[i];
            } else {
                T += s[i];
            }
            while (current < 26 && last[current] <= i) {
                current++;
            }
            while (T.size() && T.back() - 'a' <= current) {
                ans += T.back();
                T.pop_back();
            }
        }
        while (T.size()) {
            ans += T.back();
            T.pop_back();
        }
        return ans;
    }
};