#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        const int N = s.size();
        vector<vector<int>> positions(26);
        vector<bool> visited(N);
        for (int i = 0; i < N; i++) {
            if (s[i] == '*') {
                visited[i] = true;
                for (int j = 0; j < 26; j++) {
                    if (positions[j].size()) {
                        visited[positions[j].back()] = true;
                        positions[j].pop_back();
                        break;
                    }
                }
            } else {
                positions[s[i] - 'a'].push_back(i);
            }
        }
        string ans = "";
        for (int i = 0; i < N; i++) {
            if (!visited[i]) ans += s[i];
        }
        return ans;
    }
};