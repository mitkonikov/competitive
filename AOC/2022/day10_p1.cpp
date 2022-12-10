#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int Q;
    cin >> Q;
    int cycle = 0;
    ll x = 1;
    ll ans = 0;
    auto check = [&]() {
        if ((cycle + 20) % 40 == 0) {
            ans += x * cycle;
        }
    };
    for (int i = 0; i < Q; i++) {
        string instruction;
        cin >> instruction;
        if (instruction == "noop") {
            cycle++; check();
        } else {
            ll what;
            cin >> what;
            cycle++; check();
            cycle++; check();
            x += what;
        }
    }
    cout << ans << endl;
    return 0;
}