#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, H, M;
    cin >> n >> H >> M;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (v[i].first > H || (v[i].first == H && v[i].second >= M)) {
            ans = min(ans, (v[i].first - H) * 60 + v[i].second - M);
        }
    }
    if (ans == INT_MAX) {
        ans = (23 - H) * 60 + 60 - M + v[0].first * 60 + v[0].second;
    }
    cout << ans / 60 << " " << ans % 60 << endl;
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