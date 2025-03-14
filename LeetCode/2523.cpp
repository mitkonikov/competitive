#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int MX = 1e6 + 100;
        vector<bool> prime(MX, true);
        prime[1] = false;
        for (int i = 2; i < MX; i++) {
            for (int j = i + i; j < MX; j += i) {
                prime[j] = false;
            }
        }
        vector<int> primes_in_range;
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                primes_in_range.push_back(i);
            }
        }
        int ans = 1e9;
        int n1 = -1, n2 = -1;
        for (int i = 0; i < static_cast<int>(primes_in_range.size()) - 1; i++) {
            int a = primes_in_range[i];
            int b = primes_in_range[i + 1];
            if (b - a < ans) {
                ans = b - a;
                n1 = a;
                n2 = b;
            }
        }

        return { n1, n2 };
    }
};