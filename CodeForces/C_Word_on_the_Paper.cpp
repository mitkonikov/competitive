#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    vector<string> G(8);
    for (int i = 0; i < 8; i++) cin >> G[i];
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (G[i][j] != '.') {
                for (int k = i; k < 8; k++) {
                    if (G[k][j] == '.') break;
                    cout << G[k][j];
                }
                cout << endl;
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