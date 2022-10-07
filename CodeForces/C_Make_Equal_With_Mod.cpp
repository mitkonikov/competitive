#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> v(n);
    bool is_one = false;
    bool is_cons = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) is_one = true;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1] + 1) {
            is_cons = true;
            break;
        }
    }
    if (!is_one) {
        cout << "YES" << endl;
    } else {
        if (is_cons) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
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