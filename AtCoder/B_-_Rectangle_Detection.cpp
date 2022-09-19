#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n = 10;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int a = 100, b = -100, c = 100, d = -100;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (v[i][j] == '#') {
            a = min(a, i);
            b = max(b, i);
            c = min(c, j);
            d = max(d, j);
        }
    }
    cout << a+1 << " " << b+1 << endl;
    cout << c+1 << " " << d+1 << endl;
    cout << flush;
    return 0;
}