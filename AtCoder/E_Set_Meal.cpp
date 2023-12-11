#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];
    // sort B in decreasing order
    vector<pair<int, int>> BD(M);
    for (int i = 0; i < M; i++) BD[i] = { B[i], i };
    sort(BD.rbegin(), BD.rend());
    vector<int> MB(M);
    for (int i = 0; i < M; i++) MB[BD[i].second] = i;
    vector<vector<int>> P(N);
    for (int i = 0; i < L; i++) {
        int main, side;
        cin >> main >> side;
        side = MB[side - 1];
        P[main - 1].push_back(side);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int best = 0;
        sort(P[i].begin(), P[i].end());
        for (auto side: P[i]) {
            if (side == best) best++;
            else break;
        }
        if (best < M) ans = max(ans, (ll)BD[best].first + A[i]);
    }
    cout << ans << endl;
    return 0;
}