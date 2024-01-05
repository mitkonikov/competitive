#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    vector<string> A(3);
    for (int i = 0; i < 3; i++) cin >> A[i];
    vector<int> frq(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == '?') {
                for (int j = 0; j < 3; j++) {
                    if (A[i][j] != '?') frq[A[i][j] - 'A']++;
                }
                for (int j = 0; j < 3; j++) {
                    if (frq[j] == 0) {
                        cout << (char)('A' + j) << endl;
                        return;
                    }
                }
                return;
            }
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