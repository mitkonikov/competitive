#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    vector<int> b(k - 1);
    for (int i = 0; i < k - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }
    if (!b.empty() && !is_sorted(b.begin(), b.end())) {
        cout << "No" << endl;
        return;
    }
    if (b.empty()) {
        cout << "Yes" << endl;
        return;
    }
    if ((ll)(n - k + 1) * b[0] >= a[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}