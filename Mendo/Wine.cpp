// Task: https://mendo.mk/Task.do?id=57

#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline bool umin(ll& a, ll b) {
    if (b < a) { a = b; return true; }
    return false;
}

int main() {
    int n, h;
    ll k; // The goal
    cin >> n >> h >> k;
    vector<ll> prices(n, 0);
    vector<ll> values(n, 0);
    vector<int> own(h, 0);
    for (int i = 0; i < h; i++) cin >> own[i];
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> values[i];
    int half = n / 2;
    ll money = 0;
    for (int i = 0; i < h; i++) {
        money += prices[own[i] - 1];
    }
    vector<pair<ll, ll>> dp((1 << half));
    for (int i = 0; i < (1 << half); i++) {
        ll price = 0;
        ll value = 0;
        for (int j = 0; j < half; j++) {
            if (i & (1 << j)) {
                price += prices[j];
                value += values[j];
            }
        }
        dp[i] = { value, price };
    }
    sort(dp.begin(), dp.end());
    vector<pair<ll, ll>> dp_min(dp);
    for (int j = dp.size() - 2; j >= 0; j--) {
        umin(dp_min[j].second, dp_min[j+1].second);
    }
    int other_half = n - half;
    ll ans = LLONG_MAX;
    for (int i = 0; i < (1 << other_half); i++) {
        ll price = 0;
        ll value = 0;
        for (int j = 0; j < other_half; j++) {
            if (i & (1 << j)) {
                price += prices[half + j];
                value += values[half + j];
            }
        }
        ll left_over = k - value;
        if (left_over < 0) {
            ans = min(ans, price - money);
            continue;
        }
        auto it = lower_bound(
            dp_min.begin(), 
            dp_min.end(),
            make_pair(left_over, 0LL)) 
                - dp_min.begin();

        for (int off = -1; off <= 1; off++) {
            if (it + off < 0) continue;
            if (it + off < dp_min.size() 
                && dp_min[it+off].first >= left_over) {
                    ans = min(ans, price + dp_min[it+off].second - money);
            }
        }
    }
    if (ans == LLONG_MAX) cout << -1 << endl;
    else cout << max(0LL, ans) << endl;
    return 0;
}