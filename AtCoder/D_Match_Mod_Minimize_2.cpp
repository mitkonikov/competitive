#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    int ptr = 0;
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        while (ptr < B.size() && (A[i] + B[ptr]) < M) {
            ans += B[ptr];
            ptr++;
        }
        // match A[i] and B[ptr]
        if (ptr < B.size()) {
            ans += (A[i] + B[ptr]) % M;
            ptr++;
        } else {
            ans += A[i];
        }
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