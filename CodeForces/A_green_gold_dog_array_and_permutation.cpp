#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<pair<int, int>> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = { A[i], i };
    }
    sort(B.begin(), B.end());
    vector<int> ans(N);
    for (int i = N; i >= 1; i--) {
        ans[B[N-i].second] = i;
    }
    for (auto el: ans) cout << el << " ";
    cout << endl;
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