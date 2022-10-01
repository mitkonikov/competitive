#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += x;
    }
    ans = max(0, ans - k);
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