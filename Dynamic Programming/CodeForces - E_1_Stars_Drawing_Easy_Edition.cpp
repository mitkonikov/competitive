//
//  This is also the solution for the Hard Edition of the same problem.
// 

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mxn = 1e3 + 100;
int dp[mxn][mxn][4];
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
const int op[4] = { 1, 0, 3, 2 };

inline void umax(int& a, int b) {
    a = max(a, b);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, 0, sizeof dp);

    // take care of the four directions at once
    int dos[4] = { 0, 0, 0, 0 };
    int doe[4] = { m, m, n, n };
    int dis[4] = { n-1, 0, m-1, 0 };
    int die[4] = { -1, n, -1, m };
    int swp[4] = { 1, 1, 0, 0 };
    for (int dir = 0; dir < 4; dir++) {
        for (int i = dos[dir]; i < doe[dir]; i++) {
            int cur = 0;
            for (int j = dis[dir]; j != die[dir]; j += dx[dir] + dy[dir]) {
                if (swp[dir]) swap(i, j);
                if (a[i][j] == '*') {
                    dp[i][j][op[dir]] = cur;
                    cur++;
                } else {
                    cur = 0;
                }
                if (swp[dir]) swap(i, j);
            }
        }
    }

    vector<vector<int>> pref_h(n, vector<int>(m, false));
    vector<vector<int>> pref_v(n, vector<int>(m, false));
    vector<pair<int, int>> ans;
    vector<int> ans_star;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mn = INT_MAX;
            for (int dir = 0; dir < 4; dir++) {
                mn = min(mn, dp[i][j][dir]);
            }

            if (mn == 0) continue;

            umax(pref_h[i][j-mn], mn * 2 + 1);
            umax(pref_v[i-mn][j], mn * 2 + 1);
            ans.push_back({ i, j });
            ans_star.push_back(mn);
        }
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            cur = max(cur, pref_h[i][j]);
            if (cur > 0) {
                a[i][j] = '.';
                cur--;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            cur = max(cur, pref_v[j][i]);
            if (cur > 0) {
                a[j][i] = '.';
                cur--;
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        for (int j = 0; j < m && ok; j++) {
            if (a[i][j] == '*') {
                ok = false;
            }
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << " " << ans_star[i] << endl;
    }

    return 0;
}