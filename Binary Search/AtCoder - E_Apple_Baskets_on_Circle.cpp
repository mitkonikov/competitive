#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll L = 0, R = K + 10;
    while (L + 1 < R) {
        ll MID = L + (R - L) / 2;
        ll eaten = 0;
        for (int i = 0; i < N; i++) {
            eaten += min(A[i], MID);
        }
        if (eaten <= K) {
            L = MID;
        } else {
            R = MID;
        }
    }
    for (int i = 0; i < N; i++) {
        ll eat = min(A[i], L);
        A[i] -= eat;
        K -= eat;
    }
    assert(K <= N);
    for (int i = 0; i < N && K > 0; i++) {
        if (A[i]) {
            K--;
            A[i]--;
        }
    }
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
    return 0;
}