#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), [&](auto a, auto b) {
        int m1 = min(a.first, a.second);
        int m2 = min(b.first, b.second);
        if (m1 == m2) {
            int mx1 = max(a.first, a.second);
            int mx2 = max(b.first, b.second);
            return mx1 < mx2;
        }
        return m1 < m2;
    });
    for (int i = 0; i < N; i++) {
        cout << A[i].first << " " << A[i].second << " ";
    }
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