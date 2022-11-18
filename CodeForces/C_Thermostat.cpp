#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (b > a) {
        if ((b-a)>=x) {
            cout << 1 << endl;
        } else {
            if ((r-b)>=x || (a-l)>=x) {
                cout << 2 << endl;
            } else {
                if (abs(l-a)>=x && abs(r-b)>=x) {
                    cout << 3 << endl;
                } else if (abs(r-a)>=x && abs(l-b)>=x) {
                    cout << 3 << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    } else { // a > b
        if (abs(b-a)>=x) {
            cout << 1 << endl;
        } else {
            if ((r-a)>=x || (b-l)>=x) {
                cout << 2 << endl;
            } else {
                if (abs(l-b)>=x && abs(r-a)>=x) {
                    cout << 3 << endl;
                } else if (abs(r-b)>=x && abs(l-a)>=x) {
                    cout << 3 << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
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