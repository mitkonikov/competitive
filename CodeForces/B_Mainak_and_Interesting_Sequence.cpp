#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << "No" << endl;
        return;
    }

    if (n % 2 == 1) {
        cout << "Yes" << endl;
        for (int i = 0; i < n - 1; i++) cout << 1 << " ";
        cout << m - (n-1) << endl;
    } else {
        if (m % 2 == 0) {
            cout << "Yes" << endl;
            int diff = m - (n-2); diff /= 2;
            for (int i = 0; i < n - 2; i++) cout << 1 << " ";
            cout << diff << " ";
            cout << diff << endl;
        } else {
            if (n % m == 0) {
                cout << "Yes" << endl;
                for (int i = 0; i < n/m; i++) {
                    cout << n/m << " ";   
                }
                cout << endl;
            } else {
                cout << "No" << endl;
                return;
            }
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