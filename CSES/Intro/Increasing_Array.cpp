#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 1; i < N; i++) {
        if (A[i] < A[i-1]) {
            ans += A[i-1] - A[i];
        }
        A[i] = max(A[i], A[i-1]);
    }
    cout << ans << endl;
    return 0;
}