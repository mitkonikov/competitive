#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        const int N = s.size();
        int x = 0, y = 0;
        map<pair<int, int>, char> mp;
        bool down = true;
        for (int i = 0; i < N; i++) {
            if (down) {
                mp[make_pair(x, y)] = s[i];
                x++;
                if (x == numRows) {
                    down = false;
                    x -= 2;
                    y++;
                }
            } else {
                mp[make_pair(x, y)] = s[i];
                x--;
                y++;
                if (x < 0) {
                    x += 2;
                    y--;
                    down = true;
                }
            }
        }
        vector<string> rows(numRows);
        for (auto& [p, c] : mp) {
            rows[p.first].push_back(c);
        }
        string ans = "";
        for (auto& el : rows) ans += el;
        return ans;
    }
};