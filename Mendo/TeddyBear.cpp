// Task: https://mendo.mk/Task.do?id=360

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MXN = 100010;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bitset<MXN> dp;
    dp[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        bitset<MXN> current = dp;
        for (int k = 0; k < a[i]; k++) {
            current <<= 1;
        }
        dp |= current;
    }
    int ans = INT_MAX;
    for (int i = 0; i < MXN; i++) {
        if (dp[i]) {
            ans = min(ans, abs(sum - 2 * i));
        }
    }
    cout << ans << endl;
    return 0;
}