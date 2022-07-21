#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<ll>> v(N+1, vector<ll>(2, 0));
    v[N][0] = 1;
    for (int i = N; i >= 2; i--) {
        v[i][1] += v[i][0] * X;
        v[i-1][0] = v[i][1] + v[i][0];
        v[i-1][1] = v[i][1] * Y;
    }

    cout << v[1][1] << endl;
    cout << flush;
    return 0;
}