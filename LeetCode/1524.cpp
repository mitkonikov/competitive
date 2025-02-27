#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        const int N = arr.size();
        // odd - odd = even
        // odd - even = odd <
        // even - odd = odd <
        // even - even = even
        vector<ll> pref(N);
        for (int i = 0; i < N; i++) {
            if (i) pref[i] += pref[i-1];
            pref[i] += arr[i];
        }
        vector<int> even(N), odd(N);
        for (int i = 0; i < N; i++) {
            if (pref[i] % 2 == 0) {
                even[i]++;
            } else {
                odd[i]++;
            }
            if (i) {
                even[i] += even[i-1];
                odd[i] += odd[i-1];
            }
        }
        int ans = (arr[0] % 2 == 1);
        for (int i = 0; i < N; i++) {
            if (pref[i] % 2 == 0) {
                if (i) ans = (ans + odd[i-1]) % MOD;
            } else {
                if (i) ans = (ans + even[i-1] + 1) % MOD;
            }
        }
        return ans;
    }
};