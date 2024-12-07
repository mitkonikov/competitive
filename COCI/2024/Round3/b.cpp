#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<vector<int>> masks(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < M; j++) {
            masks[i][j] = S[j] == '1';
        }
    }
    vector<int> vm(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (masks[i][j]) vm[j] |= (1 << i);
        }
    }
    vector<int> popcount((1 << N));
    for (int mask = 0; mask < (1 << N); mask++) {
        popcount[mask] = __builtin_popcount(mask);
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> frq(M);
        int bitcount = popcount[mask];
        for (int j = 0; j < M; j++) {
            frq[j] = popcount[vm[j] & mask];
        }
        sort(frq.rbegin(), frq.rend());
        int combo = 0;
        for (int j = 0; j < M; j++) {
            if (frq[j] == 0) break;
            combo += frq[j];
            ans = max(ans, combo - X * bitcount - Y * (j + 1));
        }
    }
    cout << ans << endl;
    return 0;
}