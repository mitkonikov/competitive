#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << 2 * n << endl;

    if (n % 4 != 0) cout << n % 4;
    while (n % 4 != 0) n--;
    while (n > 0) {
        cout << 4;
        n -= 4;
    }

    cout << endl;
    cout << flush;
    return 0;
}