#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == i + 1) count++;
    }
    cout << (count + 1) / 2 << endl;
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