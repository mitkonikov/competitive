#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int mismatches = 0;
    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N-1-i]) mismatches++;
    }
    for (int i = 0; i <= N; i++) {
        // can we do it with i flips
        if (i < mismatches) {
            cout << 0;
            continue;
        }

        if (i == mismatches) {
            cout << 1;
            continue;
        }

        int left = i - mismatches; // matches 00, 11
        int mx = N - mismatches * 2;

        if (left > mx) {
            cout << 0;
            continue;
        }

        if (S.size() % 2 == 1) {
            cout << 1;
        } else {
            cout << ((left % 2 == 0) ? "1" : "0");
        }
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