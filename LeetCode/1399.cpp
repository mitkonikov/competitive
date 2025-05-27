#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int T = i;
            while (T > 0) {
                sum += T % 10;
                T /= 10;
            }
            mp[sum]++;
        }
        int largest = 0;
        for (auto& [k, v]: mp) {
            largest = max(largest, v);
        }
        int ans = 0;
        for (auto& [k, v]: mp) {
            if (v == largest) ans++;
        }
        return ans;
    }
};