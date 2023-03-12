#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    struct where {
        int value, x, y;
        bool operator<(const where& other) const {
            return (value < other.value);
        }
    };
    vector<where> A;
    A.reserve(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            A.push_back({ x, i, j });
        }
    }
    sort(A.begin(), A.end());
    auto eval = [&](int mid) {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i <= mid; i++) {
            dp[A[i].x][A[i].y]++;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i - 1 >= 0) dp[i][j] += dp[i-1][j];
                if (j - 1 >= 0) dp[i][j] += dp[i][j-1];
                if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] -= dp[i-1][j-1];
            }
        }
        auto query = [&](int x, int y) {
            return dp[x][y] - (x-K<0?0:dp[x-K][y]) - (y-K<0?0:dp[x][y-K]) + ((x-K<0||y-K<0)?0:dp[x-K][y-K]);
        };
        int target = (K * K) / 2 + 1;
        for (int i = K - 1; i < N; i++) {
            for (int j = K - 1; j < N; j++) {
                if (query(i, j) >= target) {
                    return true;
                }
            }
        }
        return false;
    };
    int L = 0, R = N * N - 1;
    while (R - L > 1) {
        int MID = (R + L) / 2;
        if (eval(MID)) {
            R = MID;
        } else {
            L = MID;
        }
    }
    if (R - 1 >= 0 && eval(R - 1)) R--;
    cout << A[R].value << endl;
    return 0;
}