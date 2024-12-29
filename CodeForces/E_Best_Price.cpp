#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    map<int, pair<int, int>> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]].first++;
        mp[B[i]].second++;
    }
    ll ans = 0;
    ll cool = N;
    ll started = 0;
    for (auto [id, p]: mp) {
        auto [a, b] = p;
        if (started <= K) ans = max(ans, (ll)(cool + started) * id);
        cool -= a;
        started += a;
        started -= b;
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