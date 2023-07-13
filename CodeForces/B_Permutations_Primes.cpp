#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return;
    }
    if (N == 2) {
        cout << 1 << " " << 2 << endl;
        return;
    }
    vector<int> A(N, -1);
    A[0] = 2;
    A[N-1] = 3;
    int p = 4;
    if (N % 2 == 0) {
        A[N / 2] = 1;
        for (int i = 0; i < N; i++) {
            if (A[i] == -1) A[i] = p++;
        }
    } else {
        A[N / 2] = 1;
        for (int i = 0; i < N; i++) {
            if (A[i] == -1) A[i] = p++;
        }
    }
    for (auto el: A) cout << el << " ";
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