#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> frq(510);
        for (int i = 0; i < arr.size(); i++) {
            frq[arr[i]]++;
        }
        for (int i = 500; i >= 1; i--) {
            if (frq[i] == i) return i;
        }
        return -1;
    }
};