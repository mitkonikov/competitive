#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> chosen(26, -1);
    string S;
    cin >> S;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        int c = S[i] - 'a';
        if (chosen[c] == -1) {
            chosen[c] = (i % 2 == 0);
        } else {
            ok &= (chosen[c] == (i % 2 == 0));
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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