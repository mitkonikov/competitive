#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    bool all_neg = 1, all_pos = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] >= 1) all_neg = 0;
        if (A[i] < 0) all_pos = 0;
    }
    if (all_neg) {
        cout << N - 1 << endl;
        for (int i = N - 2; i >= 0; i--) {
            cout << i + 1 << " " << i + 2 << endl;
        }
        return;
    }
    if (all_pos) {
        cout << N - 1 << endl;
        for (int i = 1; i < N; i++) {
            cout << i + 1 << " " << i << endl;
        }
        return;
    }
    vector<pair<int, int>> ops;
    int mx_i = max_element(A.begin(), A.end()) - A.begin();
    int mn_i = min_element(A.begin(), A.end()) - A.begin();
    while (A[mx_i] < abs(A[mn_i])) {
        ops.push_back({ mx_i, mx_i });
        A[mx_i] += A[mx_i];
    }
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            ops.push_back({ i, mx_i });
            A[i] += A[mx_i];
        }
    }
    for (int i = 1; i < N; i++) {
        ops.push_back({ i, i - 1 });
        A[i] += A[i-1];
    }
    cout << ops.size() << endl;
    for (auto [i, j]: ops) {
        cout << i + 1 << " " << j + 1 << endl;
    }
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