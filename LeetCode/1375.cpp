#include <bits/stdc++.h>
using namespace std;

struct Tree {
    vector<int> fwt;
    Tree(int N) {
        fwt.resize(N + 1);
    }

    void add(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind) fwt[ind]+=val;
    }

    int query(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind) s += fwt[ind];
        return s;
    }
};

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        const int N = flips.size();
        Tree tree(N);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            tree.add(flips[i] - 1);
            ans += tree.query(i) == i + 1;
        }
        return ans;
    }
};