#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> fuels;
vector<ll> cost;
vector<vector<pair<ll,ll>>> dp;

ll t,s,c,f,r;
ll maxFuel;

ll dfs(ll i, ll fuel) {
    if (i >= cost.size()) return 0;
    if (dp[i].size() > 0) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (dp[i][j].first == fuel) return dp[i][j].second;
        }
    }

    ll t1 = LLONG_MAX, t2;
    ll diff = fuel - fuels[i+1];
    if (diff >= 0) {
        t1 = dfs(i+1, diff);
    }
    t2 = 500;
    t2 += (maxFuel - fuel) * cost[i];
    t2 += dfs(i+1, maxFuel - fuels[i+1]);

    ll res = min(t1,t2);
    dp[i].push_back(make_pair(fuel, res));
    return res;
}

int main() {
    cin >> t;

    for (int j = 0; j < t; j++) {
        ll res = 0;
        dp.clear();
        fuels.clear();
        cost.clear();

        cin >> s >> maxFuel >> r;

        res += maxFuel * r;

        for (int i = 0; i < s; i++) {
            cin >> f >> c;

            dp.push_back(vector<pair<ll,ll>>());
            fuels.push_back(f);
            cost.push_back(c);
        }

        res += dfs(0, maxFuel - fuels[0]);
        cout << res << endl;
    }

    return 0;
}