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
    sort(A.begin(), A.end());
    int biggest = 0;
    int current = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || abs(A[i] - A[i-1]) <= K) {
            current++;
        } else {
            biggest = max(biggest, current);
            current = 1;
        }
    }
    biggest = max(biggest, current);
    cout << N - biggest << endl;
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