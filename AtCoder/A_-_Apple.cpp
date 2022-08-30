#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;

    if (x * 3 < y) {
        cout << n * x << endl;
    } else {
        cout << (n / 3) * y + (n % 3) * x << endl;
    }

    cout << flush;
    return 0;
}