#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    ll ans = LLONG_MAX;
    for (int rot = 0; rot < N; rot++) {
        ll cost = rot * A;
        string T = S;
        for (int i = 0; i < N; i++) {
            T[i] = S[(i+rot)%N];
        }
        for (int i = 0; i < N / 2; i++) {
            cost += (B * (T[i] != T[N-1-i]));
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}