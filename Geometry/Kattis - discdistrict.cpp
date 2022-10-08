#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    double r;
    cin >> r;

    ll ans = LLONG_MAX;
    int X = -1, Y = -1;
    for (double theta = 0; theta <= 45; theta += 0.0001) {
        double x = sin(theta) * r;
        double y = cos(theta) * r;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                ll xx = floor(x) + i;
                ll yy = floor(y) + j;
                ll euc = xx*xx + yy*yy;
                if (euc > (ll)r*r) {
                    if (euc < ans) {
                        ans = euc;
                        X = xx;
                        Y = yy;
                    }
                }
            }
        }
    }

    cout << X << " " << Y << endl;
    cout << flush;
    return 0;
}