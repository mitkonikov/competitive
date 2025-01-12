#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int L = 0, SL = 0;
        int R = 0, SR = 0;
        int N = boxes.size();
        for (int i = 1; i < N; i++) {
            if (boxes[i] == '1') {
                R++;
                SR += i;
            }
        }
        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            // moving all of them to position i
            ans[i] = SL + SR;
            if (boxes[i] == '1') {
                L++;
            }
            SL += L;
            SR -= R;
            if (i + 1 < N && boxes[i+1] == '1') {
                R--;
            }
        }
        return ans;
    }
};