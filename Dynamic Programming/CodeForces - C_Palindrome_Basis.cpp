#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> v;
const int mxn = 4e4 + 100;
const int MOD = 1e9 + 7;
int dp[mxn][500];

void testCase() {
    int n;
    cin >> n;
    cout << dp[n + 1][v.size() - 1] << endl;
}

int main() {
    v.reserve(4e4);

    for (int i = 1; i < mxn; i++) {
        string s = to_string(i);
        bool ok = true;
        for (int j = 0; j < s.size() / 2; j++) {
            if (s[j] != s[s.size() - j - 1]) {
                ok = false;
                break;
            }
        }

        if (ok) v.push_back(i);
    }

    int n = v.size();
    for (int i = 0; i < mxn; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    
    for (int i = 1; i < mxn; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;

            if (i - v[j] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-v[j]][j]) % MOD;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}