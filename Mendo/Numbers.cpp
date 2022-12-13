#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int X = (A - B) / 2;
    int Y = A - X;
    if (X >= 0 && Y >= 0 && X + Y == A && Y - X == B) {
        cout << max(X, Y) << " " << min(X, Y) << endl;
    } else {
        cout << "NE MOZE" << endl;
    }
    return 0;
}