#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> pref(N);
    for (int i = 2; i < N; i += 2) pref[i] = A[i] - A[i-1];
    for (int i = 1; i < N; i++) pref[i] = pref[i-1] + pref[i];
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        int li = lower_bound(A.begin(), A.end(), l) - A.begin();
        int ri = lower_bound(A.begin(), A.end(), r) - A.begin();
        if (A[li] > l) li--;
        if (A[ri] > r) ri--;
        ll lans = pref[li];
        if (li % 2 == 1) lans += l - A[li];
        ll rans = pref[ri];
        if (ri % 2 == 1) rans += r - A[ri];
        cout << rans - lans << endl;
    }
    return 0;
}