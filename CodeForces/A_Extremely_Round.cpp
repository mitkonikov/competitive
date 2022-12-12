#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    if (n <= 9) {
        cout << n << endl;
        return;
    }
    string s = to_string(n);
    int ans = (((ll)s.size() - 1) * 9);
    ans += s[0] - '0';
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