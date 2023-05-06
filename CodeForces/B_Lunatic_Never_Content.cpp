#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(A);
    sort(B.begin(), B.end());
    if (B[0] == B.back()) {
        cout << 0 << endl;
        return;
    }
    bool pal = 1;
    for (int i = 0; i < N / 2; i++) {
        if (A[i] != A[N-1-i]) pal = 0;
    }
    if (pal) {
        cout << 0 << endl;
        return;
    }
    const int INF = -1e9;
    int ans = INF;
    for (int i = 0; i < N / 2; i++) {
        if (A[i] < A[N-1-i]) swap(A[i], A[N-1-i]);
        int diff = A[i] - A[N-1-i];
        if (diff == 0) continue;
        if (ans == INF) ans = diff;
        else ans = gcd(ans, diff);
    }
    cout << (ans == INF ? 1 : ans) << endl;
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