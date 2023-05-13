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
    vector<ll> B;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != B.back()) {
            B.push_back(A[i]);
        }
    }
    if (B.size() == 1) {
        cout << 1 << endl;
        return;
    }
    int ans = 2;
    for (int i = 1; i < B.size() - 1; i++) {
        if ((B[i]-B[i-1])*(B[i+1]-B[i])<0) ans++;
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