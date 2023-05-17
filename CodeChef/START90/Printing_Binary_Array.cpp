#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S = "";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        S += (x ? '1' : '0');
    }
    string T = S;
    reverse(T.begin(), T.end());
    if (T == S) {
        for (int i = 0; i < N; i++) {
            cout << (S[i] == '1' ? 0 : 1) << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        cout << (T[i] == '1' ? 1 : 0) << " ";
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