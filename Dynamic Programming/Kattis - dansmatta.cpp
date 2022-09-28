#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline int convert(char c) {
    if (c == 'U') return 0;
    if (c == 'H') return 1;
    if (c == 'N') return 2;
    if (c == 'V') return 3;
    return -1;
}

inline bool umin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    } return false;
}

int main() {
    const int INF = 1e9;
    int n;
    cin >> n;
    vector<vector<int>> dp(4, vector<int>(4, INF));
    dp[1][3] = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<vector<int>> new_dp(4, vector<int>(4, INF));

        if (s.size() == 1) {
            int step = convert(s[0]);
            assert(step != -1);

            for (int j = 0; j < 4; j++) {
                for (int jj = 0; jj < 4; jj++) {
                    umin(new_dp[step][j], dp[jj][j] + (step != jj));
                }
            }

            for (int j = 0; j < 4; j++) {
                for (int jj = 0; jj < 4; jj++) {
                    umin(new_dp[j][step], dp[j][jj] + (step != jj));
                }
            }
        } else {
            int step1 = convert(s[0]);
            int step2 = convert(s[1]);
            assert(step1 != -1 && step2 != -1);

            for (int rep = 0; rep < 2; rep++) {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        umin(new_dp[step1][step2], dp[i][j] + (i != step1) + (j != step2));
                    }
                }

                swap(step1, step2);
            }
        }

        dp.swap(new_dp);
    }
    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) ans = min(ans, dp[i][j]);
    cout << ans << endl;
    cout << flush;
    return 0;
}