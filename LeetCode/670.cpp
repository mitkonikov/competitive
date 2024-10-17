#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string S = to_string(num);
        int N = S.size();
        int ans = num;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (S[j] == '0') continue;
                string T = S;
                swap(T[i], T[j]);
                ans = max(ans, stoi(T));
            }
        }
        return ans;
    }
};