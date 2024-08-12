#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int a, b, c, a1, b1, c1;
    int d, e, f, d1, e1, f1;
    cin >> a >> b >> c >> a1 >> b1 >> c1;
    cin >> d >> e >> f >> d1 >> e1 >> f1;
    auto intersection = [](int x1, int y1, int x2, int y2) {
        return (x1 < y2 && y1 > x2);
    };
    if (intersection(a, a1, d, d1)
        && intersection(b, b1, e, e1)
        && intersection(c, c1, f, f1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    return 0;
}