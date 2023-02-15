#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int i = 0; i <= N / 2; i++) {
        if (S[i] == S[N-1-i]) {
            cout << N - i * 2 << endl;
            return;
        }
    }
    cout << 0 << endl;
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