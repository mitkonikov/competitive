#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    int XOR = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        XOR ^= (A[i] % 4);
    }
    cout << (XOR == 0 ? "second" : "first") << endl;
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