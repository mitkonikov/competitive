#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    ll maxPower(vector<int>& stations, int r, int k) {
        const int N = stations.size();
        ll L = 0, R = 1e18 + 10;
        vector<ll> power(N);
        int A = 0, B = 0;
        ll cur_power = 0;
        for (int i = 0; i < N; i++) {
            while (i - A > r) {
                cur_power -= stations[A];
                A++;
            }
            while (B < N && B - i <= r) {
                cur_power += stations[B];
                B++;
            }
            power[i] = cur_power;
        }
        while (R - L > 1) {
            ll M = L + (R - L) / 2;
            // check if the M can be the minimum
            vector<ll> remove(N);
            int left = k;
            bool fail = false;
            ll add = 0;
            for (int i = 0; i < N; i++) {
                ll cur = power[i] + add;
                if (cur < M) {
                    if (M - cur > left) {
                        fail = true;
                        break;
                    }
                    remove[min(N - 1, i + 2 * r)] += M - cur;
                    left -= M - cur;
                    add += M - cur;
                }
                add -= remove[i];
            }
            if (!fail) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
};