#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, M;
    ll x1, y1, x2, y2;
    cin >> N >> M >> x1 >> y1 >> x2 >> y2;
    // always 4
    int ans = 4;
    if (x1 == 1 && y1 == 1) {
        ans = min(ans, 2);
    }
    if (x2 == 1 && y2 == 1) {
        ans = min(ans, 2);
    }
    if (x1 == N && y1 == M) {
        ans = min(ans, 2);
    }
    if (x2 == N && y2 == M) {
        ans = min(ans, 2);
    }
    if (x1 == N && y1 == 1) {
        ans = min(ans, 2);
    }
    if (x2 == N && y2 == 1) {
        ans = min(ans, 2);
    }
    if (x1 == 1 && y1 == M) {
        ans = min(ans, 2);
    }
    if (x2 == 1 && y2 == M) {
        ans = min(ans, 2);
    }
    if (x1 == 1 || x2 == 1 || y1 == 1 || y2 == 1 || x1 == N || x2 == N || y1 == M || y2 == M) {
        ans = min(ans, 3);
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