#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) odd++;
    }
    if (abs(odd - (n - odd)) % 2 == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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