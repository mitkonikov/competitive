#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    deque<pair<int, ll>> dq;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, c;
            cin >> x >> c;
            dq.push_back({ c, x });
        } else {
            int c;
            cin >> c;
            ll sum = 0;
            while (c > 0) {
                auto front = dq.front();
                dq.pop_front();
                int taken = min(c, front.first);
                sum = sum + (ll)taken * front.second;
                c -= taken;
                if (c == 0) {
                    dq.push_front({ front.first - taken, front.second });
                }
            }
            cout << sum << endl;
        }
    }
    cout << flush;
    return 0;
}