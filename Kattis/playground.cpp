#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        ll sum = 0;
        vector<ll> wires(n);
        for (int i = 0; i < n; i++) {
            long double x;
            cin >> x;
            wires[i] = x * 1000;
        }
        bool ok = false;
        sort(wires.begin(), wires.end());
        for (int i = 0; i < n - 1; i++) sum += wires[i];
        for (int i = n - 1; i >= 1; i--) {
            if (sum >= wires[i]) {
                ok = true;
                break;
            }
            sum -= wires[i-1];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    cout << flush;
    return 0;
}