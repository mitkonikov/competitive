#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int N = s.size();
        int M = shifts.size();
        vector<int> events(N);
        for (int i = 0; i < M; i++) {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int d = shifts[i][2];
            events[l] += (d ? 1 : -1);
            if (r+1<N) events[r+1] += (d ? -1 : 1);
        }
        int shift = 0;
        for (int i = 0; i < N; i++) {
            shift += events[i];
            s[i] = ((s[i] - 'a' + shift + M * 26) % 26) + 'a';
        }
        return s;
    }
};