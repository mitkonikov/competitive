// Task: https://mendo.mk/Task.do?id=50

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    ll up = 0, down = 0;
    ll can_down = 0, can_up = 0;
    ll need = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] < A) {
            need = need + A - a[i];
            up = up + A - a[i];
            can_up = can_up + B - A;
        } else if (a[i] > B) {
            need = need - (a[i] - B);
            down = down + a[i] - B;
            can_down = can_down + B - A;
        } else {
            can_up = can_up + B - a[i];
            can_down = can_down + a[i] - A;
        }
    }

    if (need >= 0) {
        if (need > can_down) {
            cout << -1 << endl;
            return 0;
        }
    } else {
        if (-need > can_up) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << max(up, down) << endl;

    return 0;
}