#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    int K;
    cin >> K;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    ll acc = 0;
    for (int i = 0; i < N; i++) acc += A[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (K % 2 == 1) {
        if (B.back() > A.front()) cout << acc - A.front() + B.back() << endl;
        else cout << acc << endl;
    } else {
        if (B.back() > A.front()) {
            swap(A.front(), B.back());
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            swap(A.back(), B.front());
            ll acc = 0;
            for (int i = 0; i < N; i++) acc += A[i];
            cout << acc << endl;
        } else {
            cout << acc - A.back() + B.front() << endl;
        }
    }
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