#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> C(N);
    for (int i = 0; i < N; i++) {
        C[i] = (ll)(A[i] - (i ? A[i-1] : 0)) * (N - i);
        if (i) C[i] += C[i-1];
    }
    // 1 4 4 8
    for (int q = 0; q < Q; q++) {
        ll B;
        cin >> B;
        if (B > A.back()) {
            cout << -1 << endl;
            continue;
        }
        auto it = lower_bound(A.begin(), A.end(), B);
        int idx = it - A.begin();
        ll left = B - (idx ? A[idx-1] : 0) - 1;
        ll more = left * (N - idx);
        ll prev = (idx-1>=0?C[idx-1]:0);
        cout << prev + more + 1 << endl;
    }
    return 0;
}