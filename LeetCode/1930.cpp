#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<bool>> mat(26, vector<bool>(26, 0));
        vector<int> front(26), back(26);
        int N = s.size();
        front[s[0] - 'a']++;
        for (int i = 2; i < N; i++) back[s[i] - 'a']++;
        for (int i = 1; i < N - 1; i++) {
            for (int j = 0; j < 26; j++) {
                if (front[j] > 0 && back[j] > 0) {
                    mat[s[i] - 'a'][j] = true;
                }
            }
            front[s[i] - 'a']++;
            back[s[i+1] - 'a']--;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans += mat[i][j];
            }
        }
        return ans;
    }
};