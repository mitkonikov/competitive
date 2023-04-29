#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> prev_dp(10);
    prev_dp[v[0]]++;
    for (int i = 1; i < n; i++) {
        // 0 OP (i + 1)
        vector<int> new_dp(10);
        for (int j = 0; j < 10; j++) {
            int id_plus = (j + v[i]) % 10;
            int id_mult = (j * v[i]) % 10;
            new_dp[id_plus] = ((ll)new_dp[id_plus] + prev_dp[j]) % MOD;
            new_dp[id_mult] = ((ll)new_dp[id_mult] + prev_dp[j]) % MOD;
        }
        
        prev_dp.swap(new_dp);
    }

    for (int i = 0; i < 10; i++) {
        cout << prev_dp[i] << endl;
    }

    return 0;
}