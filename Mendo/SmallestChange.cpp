#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> C(3);
    for (int i = 0; i < 3; i++) cin >> C[i];
    int M;
    cin >> M;
    vector<vector<int>> dp(M + 1, vector<int>(3));
    vector<bool> visited(M + 1);
    visited[0] = true;
    for (int i = 0; i <= M; i++) {
        if (visited[i]) {
            for (int j = 0; j < 3; j++) {
                if (i + C[j] <= M && !visited[i + C[j]]) {
                    dp[i + C[j]] = dp[i];
                    dp[i + C[j]][j]++;
                    visited[i + C[j]] = true;
                }
            }
        }
    }
    for (int i = M; i >= 0; i--) {
        if (visited[i]) {
            cout << M - i << endl;
            for (auto el: dp[i]) cout << el << " ";
            cout << endl;
            break;
        }
    }
    return 0;
}