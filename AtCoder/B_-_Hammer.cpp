#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    
    if (x > 0) {
        if (y > x) {
            cout << x << endl;
        } else {
            if (y < 0) {
                cout << x << endl;
                return 0;
            }

            if (z > y) {
                cout << -1 << endl;
            } else {
                cout << abs(z) + abs(z-x) << endl;
            }
        }
    }

    x *= -1;
    y *= -1;
    z *= -1;

    if (x > 0) {
        if (y > x) {
            cout << x << endl;
        } else {
            if (y < 0) {
                cout << x << endl;
                return 0;
            }

            if (z > y) {
                cout << -1 << endl;
            } else {
                cout << abs(z) + abs(z-x) << endl;
            }
        }
    }

    cout << flush;
    return 0;
}