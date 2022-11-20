#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool failed = false;
    for (int i = 2; i < n; i++) {
        if (a[i] != a[i-2]) {
            failed = true;
            break;
        }
    }
    if (a[0] != a.back()) {
        
    } else {
        failed = true;
    }
    if (failed) {
        cout << n << endl;
    } else {
        cout << n / 2 + 1 << endl;
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