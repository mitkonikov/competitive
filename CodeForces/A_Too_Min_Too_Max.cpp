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
    sort(A.begin(), A.end());
    cout << abs(A[0] - A.rbegin()[0]) + abs(A[1] - A.rbegin()[0]) + abs(A.rbegin()[1] - A[1]) + abs(A.rbegin()[1] - A[0]) << endl;
    // A[0], A[-0], A[1], A[-1]
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