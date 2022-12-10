#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int mx = n - 1; mx >= 0; mx--) {
        if (mx < s - 1) break;
        ll MAX = a[mx];
        int MID = mx / 2;
        vector<vector<ll>> masks(MID + 1);
        for (int i = 0; i < (1 << MID); i++) {
            ll sum = 0;
            int bitcount = 0;
            for (int j = 0; j < MID; j++) {
                if (i & (1 << j)) {
                    sum += a[j];
                    bitcount++;
                }
            }
            masks[bitcount].push_back(sum);
        }
        for (int i = 0; i <= MID; i++) {
            sort(masks[i].begin(), masks[i].end());
        }
        int sz = mx - MID;
        for (int i = 0; i < (1 << sz); i++) {
            ll sum_me = 0;
            int bit_count = 0;
            for (int j = 0; j < sz; j++) {
                if (i & (1 << j)) {
                    sum_me += a[MID + j];
                    bit_count++;
                }
            }
            ll left_over = MAX - sum_me;
            int bit_over = s - bit_count - 1;
            if (bit_over == 0 && left_over <= 0) {
                ans += 1;
                continue;
            }
            if (bit_over >= masks.size()) continue;
            auto it = upper_bound(masks[bit_over].begin(), masks[bit_over].end(), left_over);
            if (it == masks[bit_over].end()) {
                continue;
            }
            int id = it - masks[bit_over].begin();
            int bigger = masks[bit_over].size() - id;
            ans += bigger;
        }
    }
    cout << ans << endl;
    return 0;
}