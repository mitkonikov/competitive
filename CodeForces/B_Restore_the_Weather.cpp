#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i].first;
        B[i].second = i;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[A[i].second] = B[i].first;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    } cout << endl;
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