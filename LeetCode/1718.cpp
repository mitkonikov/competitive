#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& vec, vector<bool>& is_used, int i, int num, int n) {
        while (i < vec.size() && vec[i] != 0) i++;
        
        if (i >= vec.size()) {
            return true;
        }

        for (int p = n; p >= 2; p--) {
            if (i + p >= vec.size()) continue;
            if (is_used[p]) continue;
            if (vec[i] == 0 && vec[i+p] == 0) {
                vec[i] = p;
                vec[p+i] = p;
                is_used[p] = true;
                bool res = backtrack(vec, is_used, i + 1, num - 1, n);
                if (res) return true;
                is_used[p] = false;
                vec[i] = 0;
                vec[p+i] = 0;
            }
        }

        if (!is_used[1] && vec[i] == 0) {
            vec[i] = 1;
            is_used[1] = true;
            bool res = backtrack(vec, is_used, i + 1, num - 1, n);
            if (res) return true;
            is_used[1] = false;
            vec[i] = 0;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        if (n == 1) return { 1 };
        vector<int> vec(2 * (n - 1) + 1);
        vector<bool> is_used(22);
        backtrack(vec, is_used, 0, n, n);
        for (auto& el : vec) if (el == 0) el = 1;
        return vec;
    }
};