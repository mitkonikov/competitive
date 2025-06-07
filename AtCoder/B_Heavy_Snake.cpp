#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    for (int k = 1; k <= D; k++) {
        ll mx = 0;
        for (int i = 0; i < N; i++) {
            mx = max(mx, (ll)A[i].first * (A[i].second + k));
        }
        cout << mx << endl;
    }
    return 0;
}