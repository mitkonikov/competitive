#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, T;
    cin >> N >> T;
    int ans = -1;
    int best = -1;
    vector<int> A(N), E(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }
    for (int i = 0; i < N; i++) {
        if (A[i] <= T - i && E[i] > best) {
            best = E[i];
            ans = i + 1;
        }
    }
    cout << ans << endl;
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