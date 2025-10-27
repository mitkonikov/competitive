#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int last_count = 0;
        const int N = bank.size();
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (char el : bank[i]) count += el == '1';
            ans += count * last_count;
            if (count > 0) last_count = count;
        }
        return ans;
    }
};