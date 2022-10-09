#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> mat = {{ 2, 2, 2, 3, 3 }, 
                            { 1, 1, 1, 2, 2},
                            { 0, 1, 0, 0, 2},
                            {0, 2, 0, 0, 3},
                            {2, 2, 2, 3, 3}};

vector<int> initial_states = { 5, 3, 2, 3, 5 };

int N = 5;

#define MX vector<vector<int>>
const int MOD = 1e9 + 7;

MX mult(MX a, MX b) {
    MX c(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] = ((ll)c[i][j] + ((ll)a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return c;
}

MX expo(MX a, ll power) {
    MX result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) result[i][i] = 1;
    
    while (power > 0) {
        if (power & 1LL) {
            result = mult(a, result);
            power--;
            continue;
        }

        a = mult(a, a);
        power /= 2;
    }

    return result;
}

void testCase() {
    ll K;
    cin >> K;

    if (K == 1) {
        cout << 18 << endl;
        return;
    }

    K--;
    
    MX final_dp = expo(mat, K);

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = (ans + ((ll)final_dp[i][j] * initial_states[j]) % MOD) % MOD;
        }
    }

    cout << ans << endl;
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