#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N;
    cin >> N;

    int current = 0;
    int ans = 0;
    for (int i = 1; i <= 600; i++) {
        if (N % i == 0) {
            current++;
            ans = max(ans, current);
        } else {
            current = 0;
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