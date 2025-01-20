#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> ans(N);
        vector<int> frq(N + 1);
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == B[i]) {
                count++;
            } else {
                frq[A[i]]++;
                frq[B[i]]++;
                if (frq[A[i]] == 2) {
                    count++;
                }
                if (frq[B[i]] == 2) {
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};