#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    // 1 - 1
    // 3 - 3
    // 6 - 2 * 3
    // 10 - 2 * 5
    // 15 - 3 * 5
    int m15 = N / 15;
    int ans = N;
    for (int i = max(0, m15 - 5); i <= m15; i++) {
        int left15 = N - (i * 15);
        int mx10 = left15 / 10;
        for (int j = max(0, mx10 - 5); j <= mx10; j++) {
            int left10 = left15 - (j * 10);
            int mx6 = left10 / 6;
            for (int k = max(0, mx6 - 5); k <= mx6; k++) {
                int left6 = left10 - (k * 6);
                int thr = left6 / 3 + left6 % 3;
                ans = min(ans, thr + i + j + k);
            }
        }
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