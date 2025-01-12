#include <bits/stdc++.h>
using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

long long lcm(long long x, long long y) {
    return x / gcd(x, y) * y;
}

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            int g = nums[i];
            int l = nums[i];
            int p = nums[i];
            for (int j = i + 1; j < N; j++) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                p *= nums[j];
                if (p == l * g) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};