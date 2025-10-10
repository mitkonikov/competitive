#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(x - z) < abs(y - z)) return 1;
        if (abs(y - z) < abs(x - z)) return 2;
        return 0;
    }
};