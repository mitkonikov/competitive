#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        int all = accumulate(distance.begin(), distance.end(), 0);
        const int N = distance.size();
        for (int i = start; i < (destination > start ? destination : destination + N); i++) {
            sum += distance[i % N];
        }
        return min(sum, all - sum);
    }
};