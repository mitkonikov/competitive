// Task: https://mendo.mk/Task.do?id=142
 
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
template<typename T>
inline void umin(T& a, T b) {
    if (a > b) a = b;
}
 
const ll INF = 9e9;
 
ll dp[1310][1310][2];
 
int main() {
    for (int i = 0; i < 1310; i++) {
        for (int j = 0; j < 1310; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
 
    int n, t;
    cin >> n >> t;
    n += 1;
    vector<vector<ll>> mp(2, vector<ll>(n + 10, -1));
    vector<vector<ll>> p(2);
    set<int> seen;
    seen.insert(1);
    p[1].push_back(1);
    for (int i = 0; i < n - 1; i++) {
        int pos;
        cin >> pos;
        if (!seen.count(pos)) p[pos%2].push_back(pos);
        seen.insert(pos);
    }
 
    for (int pp = 0; pp < 2; pp++) sort(p[pp].begin(), p[pp].end());
 
    int p0 = 0, p1 = 0;
    int l0 = 0, l1 = 0;
    for (int i = 1; i <= n; i++) {
        if (p[0].size() == p0 && p[1].size() == p1) {
            break;
        }
         
        if (p[0].size() == p0) {
            mp[1][i] = p[1][p1++];
        } else if (p[1].size() == p1) {
            mp[0][i] = p[0][p0++];
        } else {
            if (p[0][p0] == p[1][p1] + 1) {
                mp[0][i] = p[0][p0++];
                mp[1][i] = p[1][p1++];
            } else if (p[0][p0] < p[1][p1]) {
                mp[0][i] = p[0][p0++];
            } else {
                mp[1][i] = p[1][p1++];
            }
        }
 
        if (mp[0][i] != -1) l0 = i;
        if (mp[1][i] != -1) l1 = i;
    }
 
     
    dp[1][0][1] = 0;
 
    auto here = [&](int parity, int i) {
        ll res = mp[parity][i];
        if (res == -1) {
            if (parity == 0) {
                res = mp[1][i] + 1;
            } else {
                res = mp[0][i] - 1;
            }
        }
        return res;
    };
 
    auto travel = [&](int parity, int i) {
        return (here(parity, i) - here(parity, i-1)) / 2;
    };
     
    auto range = [&](int parity, int i, int j) {
        ll h = here(parity, i);
        ll travel_to = h;
        for (int k = i; k > j; k--) {
            if (mp[parity][k] != -1) {
                travel_to = mp[parity][k];
            }
        }
        assert(h >= travel_to);
        return (h - travel_to) / 2;
    };

    auto dist = [&](int parity, int i, int j) {
        assert(i >= j);
        return (here(parity, i) - here(parity, j)) / 2;
    };

    int lmx = max(l0, l1);
    for (int i = 1; i <= n; i++) {
        if (mp[0][i] == -1 && mp[1][i] == -1) break;
        for (int j = i; j >= 0; j--) {
            for (int k = 0; k < 2; k++) {
                umin(dp[i][j][k], dp[i-1][j][k] + travel(k, i));
                if (mp[k][i] != -1) {
                    int ret = 2;
                    if (l0 == i && l0 == lmx && k == 0) ret = 1;
                    if (l1 == i && l1 == lmx && k == 1) ret = 1;
                    umin(dp[i][i][k^1], dp[i][j][k] + t     + range(k^1, i, j) * ret);
                    umin(dp[i][i][k],   dp[i][j][k] + t * 2 + range(k^1, i, j) * 2);
                    
                    int e  = (k == 0 ? l1 : l0);
                    int re = (k == 1 ? l1 : l0);
                    if (e > i && i == re) {
                        umin(dp[e][i][k^1], dp[i][j][k] + t + range(k^1, i, j) + dist(k^1, e, i) * 2);
                    }
                }
            }
        }
    }
 
    if (p[0].empty()) {
        cout << dp[lmx][0][1] << endl;
        return 0;
    }
 
    cout << min({
        dp[l0][l1][0],
        dp[l1][l0][1],
        dp[lmx][lmx][0],
        dp[lmx][lmx][1]
    }) << endl;
 
    return 0;
}