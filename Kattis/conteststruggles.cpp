#include <bits/stdc++.h>

using namespace std;

int main() {
    double n, k;
    cin >> n >> k;

    double d, s;
    cin >> d >> s;

    double ss = k / n;
    double rr = 1 - ss;
    double ans = (d - ss * s) / rr;

    if (ans > 100 || ans < 0) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << fixed << setprecision(19) << ans << endl;

    return 0;
}