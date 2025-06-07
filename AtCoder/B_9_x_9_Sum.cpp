#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int X;
    cin >> X;
    ll sum = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j != X) sum += i * j;
        }
    }
    cout << sum << endl;
    return 0;
}