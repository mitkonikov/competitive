#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    vector<string> A(10);
    for (int i = 0; i < 10; i++) cin >> A[i];
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i][j] == 'X') {
                ans += (min({
                    i, j, 9-i, 9-j
                })) + 1;
            }
        }
    }
    cout << ans << endl;
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