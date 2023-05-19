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
    int L = 0, R = 0;
    if (A[0] == N) {
        // special case
        for (int i = 0; i < N; i++) {
            if (A[i] == N - 1) {
                R = i - 1;
                L = i - 1;
                if (i == N - 1) {
                    R = N - 1;
                    L = N - 1;
                }
            }
        }
    } else if (A.back() == N) {
        R = N - 1;
        for (int i = R - 1; i >= 0; i--) {
            if (A[i] < A[0]) {
                L = min(R, i + 1);
                break;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (A[i] == N) {
                R = i - 1;
            }
        }
        for (int i = R - 1; i >= 0; i--) {
            if (A[i] <= A[0]) {
                L = min(R, i + 1);
                break;
            }
        }
    }
    for (int i = R + 1; i < N; i++) {
        cout << A[i] << " ";
    }
    for (int i = R; i >= L; i--) {
        cout << A[i] << " ";
    }
    for (int i = 0; i < L; i++) {
        cout << A[i] << " ";
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