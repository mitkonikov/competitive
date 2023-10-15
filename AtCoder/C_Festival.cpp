#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) { cin >> A[i]; A[i]--; }
    vector<int> ans(N + 1, INT_MAX);
    for (int i = 0; i < M; i++) {
        ans[A[i]] = A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        ans[i] = min(ans[i], ans[i+1]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] - i << endl;
    }
    return 0;
}