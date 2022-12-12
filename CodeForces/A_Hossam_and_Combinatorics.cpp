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
    sort(a.begin(), a.end());
    if (a.front() == a.back()) {
        cout << (ll)n * (n-1) << endl;
        return;
    }
    int cf = 0, cb = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) cf++;
        if (a[i] == a.back()) cb++;
    }
    cout << (ll)cf * cb * 2 << endl;
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