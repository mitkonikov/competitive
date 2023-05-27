#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    bool ok = 1;
    for (int i = 0; i < N; i++) {
        if (S[i] == T[i]) continue;
        if (S[i] == '1' && T[i] == 'l') continue;
        if (T[i] == '1' && S[i] == 'l') continue;
        if (S[i] == '0' && T[i] == 'o') continue;
        if (T[i] == '0' && S[i] == 'o') continue;
        ok = 0;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}