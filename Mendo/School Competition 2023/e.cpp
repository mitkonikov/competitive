#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int L = 0, R = 0;
    vector<int> occ(K);
    int count = 0;
    int ans = 0;
    occ[A[0]]++;
    while (R < N - 1) {
        R++;
        if (A[R] >= K) {
            if (count == K) {
                ans = max(ans, R - L + 1);
            }
            continue;
        }
        bool ok = (occ[A[R]] == 2);
        occ[A[R]]++;
        while (occ[A[R]] > 3) {
            if (A[L] < K && occ[A[L]] == 3) count--;
            if (A[L] < K) occ[A[L]]--;
            L++;
        }
        if (ok && occ[A[R]] == 3) {
            count++;
        }
        if (count == K) {
            ans = max(ans, R - L + 1);
        }
    }
    if (count == K) {
        ans = max(ans, R - L + 1);
    }
    cout << ans << endl;
    return 0;
}