#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    bool ans = true;
    for (int i = 0; i < N; i++) {
        if (A[i] <= i * 2 || A[i] <= (N - i - 1) * 2) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
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