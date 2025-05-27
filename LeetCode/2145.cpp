#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        const int N = differences.size() + 1;
        vector<ll> seq(N);
        for (int i = 1; i < N; i++) {
            seq[i] = seq[i-1] + differences[i-1];
        }
        ll mn = *min_element(seq.begin(), seq.end());
        ll mx = *max_element(seq.begin(), seq.end());
        ll offset = lower - mn;
        mn += offset;
        mx += offset;
        if (mx > upper) return 0;
        return upper - mx + 1;
    }
};