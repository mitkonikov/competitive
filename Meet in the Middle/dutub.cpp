#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int dp[2][1024];
vector<pair<int, ll>> films;

inline void umin(int& a, int b) {
    a = min(a, b);
}

int main() {
    for (int rep = 0; rep < 2; rep++) {
        for (int mask = 0; mask < 1024; mask++) {
            dp[rep][mask] = INT_MAX;
        }
    }

    int n;
    cin >> n;
    films.resize(n);

    int all = 0;

    for (int i = 0; i < n; i++) {
        string cat;
        cin >> films[i].first >> cat;
        films[i].second = 0;
        for (int j = 0; j < cat.size(); j++) {
            films[i].second |= (1LL << (cat[j] - 'a'));
            all |= (1LL << (cat[j] - 'a'));
        }
    }

    int L = 0, R = n / 2;
    for (int rep = 0; rep < 2; rep++) {
        for (int mask = 0; mask < (1LL << (R-L)); mask++) {
            int cover = 0;
            int cost = 0;
            for (int j = 0; j < (R-L); j++) {
                if (mask & (1LL << j)) {
                    cover |= films[j + L].second;
                    cost += films[j + L].first;
                }
            }

            umin(dp[rep][cover], cost);
        }

        L = R;
        R = n;
    }

    int ans = INT_MAX;
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            if ((j | i) == all) {
                if (dp[0][i] == INT_MAX || 
                    dp[1][j] == INT_MAX) continue;
                umin(ans, dp[0][i] + dp[1][j]);
            }
        }
    }
    
    cout << ans << endl;
    cout << flush;
    return 0;
}