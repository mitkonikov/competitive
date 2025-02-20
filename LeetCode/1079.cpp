#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        const int N = tiles.size();
        vector<int> order(N);
        iota(order.begin(), order.end(), 0);
        unordered_set<string> us;
        do {
            string current = "";
            for (int i = 0; i < N; i++) {
                current += tiles[order[i]];
                us.insert(current);
            }
        } while (next_permutation(order.begin(), order.end()));
        return us.size();
    }
};