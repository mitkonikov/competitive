#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll B, C, D;
    cin >> B >> C >> D;
    ll diff = D - B;
    ll A = 0;
    map<int, int> mp;
    vector<ll> pos, neg;
    for (int i = 62; i >= 0; i--) {
        ll bit = (1LL << i);
        if (((B & bit) > 0) && ((C & bit) > 0)) {
            neg.push_back(i);
            mp[i] = 1;
        } else if ((C & bit) == 0) {
            pos.push_back(i);
            mp[i] = -1;
        }
    }
    bool flip = (diff < 0);
    if (flip) diff *= -1;
    for (int i = 0; i <= 62; i++) {
        ll bit = (1LL << i);
        if (diff & bit) {
            if (!flip) {
                if (mp[i] == -1) {
                    A |= bit;
                    diff -= bit;
                } else if (mp[i] == 1) {
                    A |= bit;
                    diff += bit;
                }
            } else {
                if (mp[i] == 1) {
                    A |= bit;
                    diff -= bit;
                } else if (mp[i] == -1) {
                    A |= bit;
                    diff += bit;
                }
            }
        }
    }
    if (((A | B) - (A & C)) == D) {
        cout << A << endl;
    } else {
        cout << -1 << endl;
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