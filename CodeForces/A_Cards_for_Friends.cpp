#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

ll powers[61];

void testCase() {
    ll W, H, N;
    cin >> W >> H >> N;
    ll x = 0, y = 0;
    while (W % 2 == 0) {
        x++;
        W /= 2;
    }
    while (H % 2 == 0) {
        y++;
        H /= 2;
    }
    if (powers[x] * powers[y] >= N) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    powers[0] = 1;
    for (int i = 1; i < 61; i++) {
        powers[i] = powers[i-1] * 2;
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}