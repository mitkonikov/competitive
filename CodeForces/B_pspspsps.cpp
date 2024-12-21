#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int countS = 0;
    int countP = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 's') {
            countS++;
        }
        if (S[i] == 'p') {
            countP++;
        }
    }
    if (countS == 0 || countP == 0) {
        cout << "YES" << endl;
        return;
    }
    if (countS >= 2 && countP >= 2) {
        cout << "NO" << endl;
        return;
    }
    if (S[0] == '.' && S.back() == '.') {
        cout << "NO" << endl;
        return;
    }
    bool ok = true;
    bool seen_P = false;
    int pi = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'p') {
            if (!seen_P) pi = i;
            seen_P = true;
        }
        if (seen_P && S[i] == 's') {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    if (pi == N - 1) {
        cout << "YES" << endl;
        return;
    }
    if (S[0] == 's' && countS == 1) {
        cout << "YES" << endl;
        return;
    }
    if (S[0] != 's' && countP > 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "NO" << endl;
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