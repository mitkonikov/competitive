#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    n *= 2;
    map<int, int> frq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frq[x]++;
    }
    bool ok = true;
    for (auto el: frq) {
        if (el.second > 2) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
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