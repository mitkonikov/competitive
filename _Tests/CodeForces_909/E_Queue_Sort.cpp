#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int mn = *min_element(A.begin(), A.end());
    int mn_count = 0;
    // there shouldn't be multiple blocks of minima
    for (int i = 0; i < N; i++) {
        if ((i == 0 && A[i] == mn) || (i > 0 && A[i] == mn && A[i-1] != mn)) {
            mn_count++;
        }
    }
    if (mn_count > 1) {
        cout << -1 << endl;
        return;
    }
    bool after = 0;
    vector<int> test;
    for (int i = 0; i < N; i++) {
        if (after) test.push_back(A[i]);
        else if (A[i] == mn) after = 1;
    }
    if (!is_sorted(test.begin(), test.end())) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (A[i] == mn) {
            cout << i << endl;
            return;
        }
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