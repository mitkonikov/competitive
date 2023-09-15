#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];
    int L = 0, R = 1e9 + 10;
    while (R - L > 1) {
        int MID = (R + L) / 2;
        int sell = 0, buy = 0;
        for (int i = 0; i < N; i++) sell += (MID >= A[i]);
        for (int i = 0; i < M; i++) buy += (MID <= B[i]);
        if (sell >= buy) {
            R = MID;
        } else {
            L = MID;
        }
    }
    cout << R << endl;
    return 0;
}