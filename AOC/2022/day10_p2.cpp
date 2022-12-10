#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    vector<vector<char>> screen(6, vector<char>(40, '.'));
    int Q;
    cin >> Q;
    int cycle = 0;
    ll x = 1;
    ll ans = 0;
    auto draw = [&]() {
        bool ok = false;
        for (int i = -1; i <= 1; i++) {
            if (x+i>=0 && x+i<40 && x+i==cycle%40) {
                ok = true;
                break;
            }
        }
        if (ok) screen[cycle/40][cycle%40] = '#';
    };
    auto check = [&]() {
        if ((cycle + 20) % 40 == 0) {
            ans += x * cycle;
        }
    };
    for (int i = 0; i < Q; i++) {
        string instruction;
        cin >> instruction;
        if (instruction == "noop") {
            draw(); cycle++; check();
        } else {
            ll what; cin >> what;
            draw(); cycle++; check();
            draw(); cycle++; check();
            x += what;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 40; j++) {
            cout << screen[i][j];
        } cout << endl;
    }
    cout << ans << endl;
    return 0;
}