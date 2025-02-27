#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N = arr.size();
        int ans = 2;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < i; j++) {
                int p1 = j, p2 = i;
                int count = 2;
                while (p2 < N - 1) {
                    int sum = arr[p1] + arr[p2];
                    int L = p2 + 1, R = N;
                    while (R - L > 1) {
                        int M = (R + L) / 2;
                        if (arr[M] <= sum) {
                            L = M;
                        } else {
                            R = M;
                        }
                    }
                    if (arr[L] == sum) {
                        p1 = p2;
                        p2 = L;
                        count++;
                    } else {
                        break;
                    }
                }
                ans = max(ans, count);
            }
        }
        if (ans < 3) return 0;
        return ans;
    }
};