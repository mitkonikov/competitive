#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool exists = false;
    int frq_k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            exists = true;
            frq_k++;
        }
    }
    if (!exists) {
        cout << "No" << endl;
        return;
    }
    bool ok = true;
    vector<int> b = a;
    sort(b.begin(), b.end());
    if (b[0] == b.back() && b[0] == k) {
        cout << "Yes" << endl;
        return;
    }
    if (a[n-1] == k && a[n-2] != k && frq_k == 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
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