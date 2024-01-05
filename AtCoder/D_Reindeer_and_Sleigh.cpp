#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        if (i) pref[i] = pref[i-1] + A[i];
        else pref[i] = A[i];
    }
    for (int i = 0; i < Q; i++) {
        ll X;
        cin >> X;
        auto it = upper_bound(pref.begin(), pref.end(), X);
        cout << it - pref.begin() << endl;
    }
    return 0;
}