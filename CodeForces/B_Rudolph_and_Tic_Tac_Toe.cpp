#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    vector<string> A(3);
    for (int i = 0; i < 3; i++) cin >> A[i];
    
    for (char ch: { 'X', 'O', '+' }) {
        for (int i = 0; i < 3; i++) {
            bool w = 1;
            for (int j = 0; j < 3; j++) w &= (A[i][j] == ch);
            if (w) {
                cout << ch << endl;
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            bool w = 1;
            for (int j = 0; j < 3; j++) w &= (A[j][i] == ch);
            if (w) {
                cout << ch << endl;
                return;
            }
        }
        bool w = 1;
        for (int i = 0; i < 3; i++) {
            w &= (A[i][i] == ch);
        }
        if (w) {
            cout << ch << endl;
            return;
        }
        w = 1;
        for (int i = 0; i < 3; i++) {
            w &= (A[2-i][i] == ch);
        }
        if (w) {
            cout << ch << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
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