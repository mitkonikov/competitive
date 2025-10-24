#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = LLONG_MAX;
    for (int i = 0; i < (1 << N); i++) {
        ll a = 0, b = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) a += A[j];
            else b += A[j];
        }
        ans = min(ans, max(a, b));
    }
    cout << ans << endl;
    return 0;
}