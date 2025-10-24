#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) continue;
        int mx = 0;
        for (int j = i; j < N; j++) {
            if (A[j] == 1) mx = max(mx, j);
        }
        cout << (mx - i + 1 <= K ? "YES" : "NO") << endl;
        return;
    }
    cout << "YES" << endl;
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