#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    if (S == T) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < min(S.size(), T.size()); i++) {
        if (S[i] != T[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << min(S.size(), T.size()) + 1 << endl;
    return 0;
}