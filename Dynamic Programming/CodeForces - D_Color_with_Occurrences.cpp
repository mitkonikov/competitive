#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    string text;
    cin >> text;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int T = text.size();
    vector<vector<pair<int, int>>> dp(T + 1, vector<pair<int, int>>(110, {-1,-1}));
    dp[T].clear();
    for (int i = T - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int sz = s[j].size();
            if (i + sz <= T && text.substr(i, sz) == s[j]) {
                for (int k = i+sz; k >= i+1; k--) {
                    if (dp[i].size() > dp[k].size()) {
                        dp[i] = dp[k];
                        dp[i].push_back({ j, i });
                    }
                }
            }
        }
    }
    if (dp[0].size() == 110) {
        cout << -1 << endl;
        return;
    }
    cout << dp[0].size() << endl;
    for (auto el: dp[0]) {
        cout << el.first + 1 << " " << el.second + 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}