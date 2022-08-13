#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    r--; c--;
    int mn = min({ 14-r, 14-c, r, c });
    if (mn % 2 == 0) {
        cout << "black" << endl;
    } else {
        cout << "white" << endl;
    }
    cout << flush;
    return 0;
}