#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int ans = 0;
    string S;
    cin >> S;
    S += "..";
    for (int i = 0; i < N; i++) {
        if (S[i] == '@') ans++;
        if (S[i+1] == '*' && S[i+2] == '*') break;
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