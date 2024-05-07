#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    vector<vector<bool>> dp(N + 1, vector<bool>(4, 0));
    for (int i = 0; i < N; i++) dp[i][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (dp[i][j] && S[i] == tolower(T[j])) dp[i+1][j+1] = true;
            if (dp[i][j]) dp[i+1][j] = true;
        }
    }
    bool ok = false;
    for (int i = 0; i < N + 1; i++) {
        if (dp[i][3]) ok = true;
    }
    if (T[2] == 'X') {
        for (int i = 0; i < N + 1; i++) {
            if (dp[i][2]) ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}