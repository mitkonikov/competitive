#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 1e18 + 1000;
        long long ans1 = 0;
        int N = arr.size();
        for (int i = 0; i < N; i++) {
            ans1 += abs(arr[i] - brr[i]);
        }
        ans = min(ans, ans1);

        long long ans2 = k;
        map<int, int> fq;
        for (int i = 0; i < N; i++) {
            fq[arr[i]]++;
            fq[brr[i]]--;
        }
        vector<int> la, lb;
        for (auto& [k, v] : fq) {
            if (v == 0) continue;
            if (v < 0) {
                for (int iter = 0; iter < abs(v); iter++) {
                    lb.push_back(k);
                }
            } else {
                for (int iter = 0; iter < abs(v); iter++) {
                    la.push_back(k);
                }
            }
        }
        assert(la.size() == lb.size());
        for (int i = 0; i < la.size(); i++) {
            ans2 += abs(la[i] - lb[i]);
        }

        ans = min(ans, ans2);
        return ans;
    }
};