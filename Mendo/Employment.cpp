// Task: https://mendo.mk/Task.do?id=152

#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void bit_minus(vector<int>& a, const vector<int>& b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] = max(0, a[i] - b[i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> initial_mask(n, 2);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int price, k;
        cin >> price >> k;
        sum += price;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            initial_mask[x] = max(0, initial_mask[x] - 1);
        }
    }
    map<vector<int>, int> dp;
    dp[initial_mask] = 0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int price, t;
        cin >> price >> t;
        vector<int> el(n, 0);
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            el[x-1]++;
        }
        vector<pair<vector<int>, int>> new_dp;
        for (auto v: dp) {
            auto vv = v.first;
            bit_minus(vv, el);
            new_dp.push_back({ vv, v.second + price });
        }
        for (auto v: new_dp) {
            auto it = dp.find(v.first);
            if (it == dp.end()) {
                dp[v.first] = v.second;
            } else {
                dp[v.first] = min(dp[v.first], v.second);
            }
        }
    }
    vector<int> ans(n, 0);
    cout << sum + dp[ans] << endl;
    return 0;
}