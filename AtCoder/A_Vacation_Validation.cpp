#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    L--; R--;
    string S;
    cin >> S;
    bool ok = true;
    for (int i = L; i <= R; i++) {
        ok &= (S[i] == 'o');
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}