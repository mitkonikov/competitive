#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        ans += S[i] == '1';
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