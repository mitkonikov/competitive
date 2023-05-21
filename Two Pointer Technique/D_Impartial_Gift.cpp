#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    ll D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int pA = N - 1, pB = M - 1;
    while (pA != -1 && pB != -1) {
        if (abs(A[pA] - B[pB]) <= D) {
            cout << A[pA] + B[pB] << endl;
            return 0;
        }
        if (A[pA] > B[pB]) pA--;
        else pB--;
    }
    cout << -1 << endl;
    return 0;
}