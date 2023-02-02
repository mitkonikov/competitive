#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M, D;
    cin >> N >> M >> D;
    vector<int> P(N+1), A(M+1);
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= M; i++) cin >> A[i];

    vector<int> pos(N+1);
    for (int i = 1; i <= N; i++) {
        pos[P[i]] = i;
    }

    bool not_good = true;
    for (int i = 1; i <= M - 1; i++) {
        if (!(pos[A[i]] < pos[A[i+1]] && pos[A[i+1]] <= pos[A[i]] + D)) {
            not_good = false;
            break;
        }
    }

    if (!not_good) {
        cout << 0 << endl;
        return;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= M - 1; i++) {
        int swaps = min(
            pos[A[i+1]] - pos[A[i]], 
            (D + 2 <= N ? pos[A[i]] + D + 1 - pos[A[i+1]] : INT_MAX));
        ans = min(ans, swaps);
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