#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int M, D;
    cin >> M >> D;
    int Y, M1, D1;
    cin >> Y >> M1 >> D1;
    D1++;
    if (D1 == D + 1) {
        M1++;
        D1 = 1;
    }
    if (M1 == M + 1) {
        Y++;
        M1 = 1;
    }
    cout << Y << " " << M1 << " " << D1 << endl;
    return 0;
}