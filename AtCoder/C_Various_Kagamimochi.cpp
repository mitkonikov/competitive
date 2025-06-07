#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(A.begin() + i + 1, A.end(), 2 * A[i]);
        auto id = (int)(it - A.begin());
        ans += N - id;
    }
    cout << ans << endl;
    return 0;
}