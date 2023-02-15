#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'U') y++;
        else if (S[i] == 'D') y--;
        else if (S[i] == 'R') x++;
        else x--;
        if (x == 1 && y == 1) {
            cout << "YES" << endl;
            return;
        }
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