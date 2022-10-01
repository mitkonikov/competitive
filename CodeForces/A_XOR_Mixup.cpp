#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    int XOR = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        XOR ^= a[i];
    }
    for (int i = 0; i < n; i++){
        if (a[i] == XOR ^ a[i]) {
            cout << a[i] << endl;
            return;
        }
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