#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, M, K, H;
    cin >> N >> M >> K >> H;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int diff = abs(x - H);
        if (diff == 0) continue;
        ans += (diff % K == 0 && ((ll)K * (M - 1)) >= diff);
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