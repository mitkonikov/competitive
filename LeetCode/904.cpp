#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int N = fruits.size();
        vector<int> suff(N, 1);
        for (int i = N - 2; i >= 0; i--) {
            if (fruits[i] == fruits[i+1]) {
                suff[i] = suff[i+1] + 1;
            }
        }
        vector<int> types(2, -1), counts(2, 0);
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            for (auto rep : { 0, 1 }) {
                if (fruits[i] == types[rep]) {
                    counts[rep]++;
                    swap(types[0], types[rep]);
                    swap(counts[0], counts[rep]);
                    goto c;
                }
            }

            types[1] = types[0];
            counts[1] = i+1<N ? suff[i+1] : counts[0];
            types[0] = fruits[i];
            counts[0] = 1;
            c:
            ans = max(ans, counts[0] + counts[1]);
        }
        return ans;
    }
};