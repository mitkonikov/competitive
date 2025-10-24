#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    int count = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= X || abs(i - j) >= Y) {
                count++;
            }
        }
    }
    cout << fixed << setprecision(16) << (double)count / 36 << endl;
    return 0;
}