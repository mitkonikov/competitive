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
        A[i] -= i;
    }
    sort(A.begin(), A.end());
    int target = A[(N-1)/2];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i] - target);
    }
    cout << ans << endl;
    return 0;
}