#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int M;
    cin >> M;
    vector<bool> cant(1e5 + 100);
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        cant[c] = true;
    }
    int X;
    cin >> X;
    vector<bool> dp(X + 10);
    dp[0] = 1;
    for (int i = 0; i < X; i++) {
        if (cant[i]) continue;
        if (!dp[i]) continue;
        for (int j = 0; j < N; j++) {
            dp[i + A[j]] = true;
        }
    }
    cout << (dp[X] ? "Yes" : "No") << endl;
    return 0;
}