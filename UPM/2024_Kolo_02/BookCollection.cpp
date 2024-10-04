#include "bits/stdc++.h"
#define ll long long
 
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int p = 0;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        while (p < B.size() && B[p] < A[i]) p++;
        if (p < i) {
            cout << 0 << endl;
            return 0;
        }
        ans = (ans * (p - i)) % mod;
    }
    cout << ans << endl;
    return 0;
}