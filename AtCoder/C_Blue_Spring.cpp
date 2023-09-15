#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    ll ans = sum;
    sort(A.rbegin(), A.rend());
    ll pay = 0;
    for (int i = 0; i < N; i++) {
        if (i % D == 0) {
            pay += P;
        }
        sum -= A[i];
        ans = min(ans, sum + pay);
    }
    cout << ans << endl;
    return 0;
}