#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    int L = 0, R = 1e9 + 100;
    while (R - L > 1) {
        int M = (R + L) / 2;
        ll pills = 0;
        for (int i = 0; i < N; i++) {
            if (A[i].first >= M) {
                pills += A[i].second;
            }
        }
        if (pills <= K) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << endl;
    return 0;
}