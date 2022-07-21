#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    if (M >= X && M <= N) {
        cout << T << endl;
    } else {
        cout << T - (D * (X - M)) << endl;
    }
    cout << flush;
    return 0;
}