#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& c) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < c.size(); i++) {
            int u = c[i][0];
            int v = c[i][1];
            if (v < u) swap(u, v);
            adj[v].push_back(u);
        }
        ll ans = 0;
        ll mx1 = 0;
        ll mx2 = 0;
        vector<ll> more(n + 1);
        for (int r = 1; r <= n; r++) {
            for (auto& l : adj[r]) {
                if (l > mx1) {
                    mx2 = mx1;
                    mx1 = l;
                } else if (l > mx2) {
                    mx2 = l;
                }
            }
            ans += (ll)r - mx1;
            if (mx1 > 0) more[mx1] += mx1 - mx2;
        }
        ll more_mx = 0;
        for (auto& el: more) more_mx = max(more_mx, el);
        return ans + more_mx;
    }
};