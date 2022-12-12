#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.size();

    vector<ll> dp(n, 0);

    reverse(s.begin(), s.end());

    int leafs = pow(2, k-1);
    for (int i = n-leafs; i < n; i++) {
        if (s[i] == '?') {
            dp[i] = 2;
        } else {
            dp[i] = 1;
        }
    }

    for (int i = n-leafs-1; i >= 0; i--) {
        if (s[i] == '0') {
            dp[i] = dp[2*i+2];
        } else if (s[i] == '1') {
            dp[i] = dp[2*i+1];
        } else {
            dp[i] = dp[2*i+1] + dp[2*i+2];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int index;
        char change;
        cin >> index >> change;

        // parent = (ourIndex+1) / 2 - 1;

        s[n - index] = change;
        if (n-index >= n-leafs) {
            if (s[n - index] == '?') {
                dp[n - index] = 2;
            } else {
                dp[n - index] = 1;
            }
        }

        int i = n - index;
        if (n - index >= n-leafs) i = (i+1)/2-1;
        for (; i >= 0; i = (i+1)/2-1) {
            if (s[i] == '0') {
                dp[i] = dp[2*i+2];
            } else if (s[i] == '1') {
                dp[i] = dp[2*i+1];
            } else {
                dp[i] = dp[2*i+1] + dp[2*i+2];
            }
        }

        cout << dp[0] << endl;

    }

    return 0;
}