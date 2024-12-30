#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    map<pair<int, int>, int> intervals;
    vector<int> B(2 * N + 100);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        A[i] = { X, Y };
        intervals[{ X, Y }]++;
        if (X == Y) B[X] = 1;
    }
    vector<int> pref(B.size());
    for (int i = 0; i < B.size(); i++) {
        if (i == 0) pref[i] = B[i];
        else pref[i] = pref[i-1] + B[i];
    }
    for (int i = 0; i < N; i++) {
        auto [L, R] = A[i];
        if (L == R) {
            if (intervals[{ L, R }] > 1) cout << "0";
            else cout << "1";
            continue;
        }
        int sum = pref[R] - (L == 0 ? 0 : pref[L-1]);
        if (sum == R - L + 1) cout << "0";
        else cout << "1";
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