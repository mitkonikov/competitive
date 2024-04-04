#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    if ((Y > X && Y <= X + 2) || (Y < X && Y >= X - 3)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}