#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    set<int> s;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (s.count(v[i])) {
            cout << n - i << endl;
            return;
        } else {
            s.insert(v[i]);
        }
    }
    cout << 0 << endl;
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