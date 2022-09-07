#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[(i+n-1+n)%n] - a[i]);
        mx = max(mx, a[i] - a[(i+n+1+n)%n]);
    }

    for (int i = 1; i < n; i++) {
        mx = max(mx, a[i] - a[0]);
        mx = max(mx, a[n-1] - a[i-1]);
    }

    cout << mx << endl;
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