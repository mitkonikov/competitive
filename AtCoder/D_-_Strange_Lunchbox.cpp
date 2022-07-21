#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[310][310];
int INF = INT_MAX / 310;

vector<pair<int, int>> boxes;
int n;

int main() {
    for (int i = 0; i < 310; i++) {
        for (int j = 0; j < 310; j++) {
            dp[i][j] = INF;
        }
    }

    int x, y;
    cin >> n >> x >> y;
    boxes.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }
    
    dp[0][0] = 0;
    for (int b = 0; b < n; b++) {
        for (int i = 309; i >= 0; i--) {
            for (int j = 309; j >= 0; j--) {
                if (dp[i][j] == INF) continue;
                int ni = min(i + boxes[b].first, 309);
                int nj = min(j + boxes[b].second, 309);
                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
            }
        }
    }

    int ans = INF;
    for (int i = x; i < 310; i++) {
        for (int j = y; j < 310; j++) {
            ans = min(ans, dp[i][j]);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}