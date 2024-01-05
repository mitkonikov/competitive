#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) pref[i] = A[i];
        else {
            if (i % 2 == 0) pref[i] = A[i] + pref[i-1];
            else pref[i] = pref[i-1] - A[i];
        }
    }
    set<ll> s;
    for (int i = 0; i < N; i++) {
        if (s.count(pref[i]) || pref[i] == 0) {
            cout << "YES" << endl;
            return;
        }
        s.insert(pref[i]);
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}