#include <bits/stdc++.h>

using namespace std;

void testCase() {
    int k;
    cin >> k;

    vector<pair<int, int>> heights(20);
    for (int i = 0; i < 20; i++) {
        int x;
        cin >> x;
        heights[i] = {x, i};
    }

    sort(heights.begin(), heights.end());

    int ans = 0;
    int shift = 0;
    for (int i = 0; i < 20; i++) {
        if (heights[i].second > i) {
            ans += heights[i].second - i;
        }
    }

    cout << k << " " << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}