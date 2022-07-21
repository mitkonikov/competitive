#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int d[2][2];
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> d[i][j];
    cout << d[--r][--c] << endl;
    cout << flush;
    return 0;
}