#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    int L = 1, R = min(N, M) + 1;
    while (R - L > 1) {
        int MID = (R + L) / 2;
        bool ok = false;

        vector<vector<int>> row(N, vector<int>(M, 0)), col(N, vector<int>(M, 0));
        vector<vector<int>> dp(N, vector<int>(M, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j == 0) row[i][j] = (a[i][j] >= MID);
                else row[i][j] = (a[i][j] >= MID ? row[i][j-1] + 1 : 0);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == 0) col[i][j] = (a[i][j] >= MID);
                else col[i][j] = (a[i][j] >= MID ? col[i-1][j] + 1 : 0);
            }
        }

        for (int i = 0; i < N && !ok; i++) {
            for (int j = 0; j < M && !ok; j++) {
                if (a[i][j] >= MID) {
                    int prev = (i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : 0);
                    dp[i][j] = min(prev + 1, min(row[i][j], col[i][j]));
                    if (dp[i][j] >= MID) {
                        ok = true;
                        break;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        if (ok) {
            L = MID;
        } else {
            R = MID;
        }
    }

    cout << L << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}