#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        
        vector<pair<long long, long long>> dp(n, {0, 0});
        long long result = n;
        long long contQ = 0;
        if (s[0] == '0') {
            dp[0].first = 1;
        } else if (s[0] == '1') {
            dp[0].second = 1;
        } else {
            dp[0].first = 1;
            dp[0].second = 1;
            contQ++;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                result += dp[i-1].second;
                dp[i] = { dp[i-1].second + 1, 0 };

                if (contQ > 0) {
                    result -= (contQ-1)*(contQ)/2;
                    contQ = 0;
                }
            } else if (s[i] == '1') {
                result += dp[i-1].first;
                dp[i] = { 0, dp[i-1].first + 1 };
                
                if (contQ > 0) {
                    result -= (contQ-1)*(contQ)/2;
                    contQ = 0;
                }
            } else {
                result += dp[i-1].first;
                result += dp[i-1].second;
                dp[i] = { dp[i-1].second + 1 , dp[i-1].first + 1 };
                contQ++;
            }
        }

        if (contQ > 0) {
            result -= (contQ-1)*(contQ)/2;
            contQ = 0;
        }

        cout << result << endl;
    }
    return 0;
}