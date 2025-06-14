#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<long long> fwt;

    FenwickTree() {}

    FenwickTree(int n) {
        fwt.resize(n + 1, 1e9);
    }

    void addFWT(int ind, long long val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind] = min(fwt[ind], val);
    }

    long long getFWT(int ind) {
        long long s = 1e9;
        for (ind++; ind > 0; ind-=ind&-ind)
            s = min(s, fwt[ind]);
        return s;
    }
};

class Solution {
public:
    int maxDifference(string s, int k) {
        int length = s.size();
        int result = INT_MIN;

        for (int first = 0; first < 5; ++first) {
            for (int second = 0; second < 5; ++second) {
                if (first == second) continue;

                vector<int> diff(length + 1, 0);
                vector<int> parityA(length + 1, 0);
                vector<int> parityB(length + 1, 0);
                vector<int> countB(length + 1, 0);

                for (int i = 1; i <= length; ++i) {
                    int digit = s[i - 1] - '0';
                    diff[i] = diff[i - 1] + (digit == first ? 1 : 0) - (digit == second ? 1 : 0);
                    parityA[i] = (parityA[i - 1] + (digit == first ? 1 : 0)) & 1;
                    parityB[i] = (parityB[i - 1] + (digit == second ? 1 : 0)) & 1;
                    countB[i] = countB[i - 1] + (digit == second ? 1 : 0);
                }

                array<array<FenwickTree, 2>, 2> pref;
                for (auto i : { 0, 1 }) {
                    for (auto j : { 0, 1 }) {
                        pref[i][j] = FenwickTree(length + 1);
                    }
                }

                for (int j = 0; j <= length; ++j) {
                    if (j >= k) {
                        int back = j - k;
                        int pA = parityA[back];
                        int pB = parityB[back];
                        int bCount = countB[back];
                        pref[pA][pB].addFWT(bCount, diff[back]);
                    }

                    if (j > 0 && countB[j] > 0) {
                        int altA = 1 - parityA[j];
                        int curB = parityB[j];
                        int minPrev = pref[altA][curB].getFWT(countB[j] - 1);

                        if (minPrev != 1e9) {
                            result = max(result, diff[j] - minPrev);
                        }
                    }
                }
            }
        }

        return result == INT_MIN ? 0 : result;
    }
};