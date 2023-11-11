#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> A(N);
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i + 1]) A[i] = 1;
    }
    vector<int> pref(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) pref[i] = A[i];
        else pref[i] = pref[i-1] + A[i];
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        // [l, r-1]
        cout << pref[r-1] - (l == 0 ? 0 : pref[l-1]) << endl;
    }
    return 0;
}