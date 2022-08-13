#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    map<int, int> frq;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        frq[x]++;
    }
    bool ok = true;
    for (auto it: frq) {
        if (!(it.second == 3 || it.second == 2)) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}